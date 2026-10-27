#!/usr/bin/env python3
"""
Author: doriani <doriani@student.42roma.it>
Author: gmartin <gmartin@student.42roma.it>
Date: 2025-10-29
Purpose: Train a one-vs-all logistic regression classifier for Hogwarts houses.
Description:
    Reads dataset_train.csv, preprocesses the data, and trains four binary
    logistic regression classifiers (one per Hogwarts house) using gradient
    descent.  Supports batch GD, stochastic GD, and mini-batch GD.

    Outputs a JSON file containing learned weights and preprocessing
    parameters so that logreg_predict.py can reproduce the same pipeline.

    See also V3_logistic_regression_walkthrough.ipynb for a step-by-step
    walkthrough.
"""
import argparse
import json
import sys
from pathlib import Path

import numpy as np
import pandas as pd

from describe import mean, std
from math_utils import sigmoid, cost_function, compute_gradient
from plot_utilities import get_courses, pearson, pair_combinations

# ──────────────────────────── constants ────────────────────────────

HOUSES = ["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"]

# Hard-coded feature set derived from pair-plot / scatter-plot analysis.
# Chosen to maximise inter-house separation while avoiding highly-correlated
# redundant pairs (e.g., Astronomy ↔ Defense Against the Dark Arts).
DEFAULT_FEATURES = [
    "Herbology",
    "Defense Against the Dark Arts",
    "Ancient Runes",
    "Charms",
    "Divination",
    "Flying",
]


# ──────────────────────────── arg parsing ──────────────────────────

def get_args():
    """Parse command-line arguments."""
    p = argparse.ArgumentParser(
        description="Train a logistic-regression Sorting Hat",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    p.add_argument("dataset", metavar="FILE", type=Path,
                   help="CSV training dataset (e.g. dataset_train.csv)")
    p.add_argument("--optimizer", choices=["batch", "sgd", "minibatch"],
                   default="batch",
                   help="Gradient-descent variant to use")
    p.add_argument("--lr", type=float, default=0.1,
                   help="Learning rate (alpha)")
    p.add_argument("--epochs", type=int, default=1000,
                   help="Number of training epochs")
    p.add_argument("--batch-size", type=int, default=32,
                   help="Batch size (only used with --optimizer minibatch)")
    p.add_argument("--auto-select", action="store_true",
                   help="Automatically select features instead of using the "
                        "hard-coded default set")
    p.add_argument("--output", "-o", type=Path, default=Path("weights.json"),
                   help="Output path for the learned weights file")
    p.add_argument("--cross-validate", action="store_true",
                   help="Run 5-fold cross-validation before training to "
                        "verify the model generalises (does not affect the "
                        "final weights — diagnostic only)")
    return p.parse_args()


# ──────────────────────── feature selection ─────────────────────────

def auto_select_features(df, max_features=6, corr_threshold=0.85):
    """
    Automatically select features that best separate houses.

    Strategy:
      1. For each feature, compute the between-house variance of means
         (features where house means differ greatly are more discriminative).
      2. Rank features by discriminative power.
      3. Greedily pick the top features, skipping any that are too highly
         correlated (|r| > corr_threshold) with an already-selected feature.

    Arguments:
        df: pandas DataFrame with 'Hogwarts House' and course columns
        max_features: maximum number of features to select
        corr_threshold: skip features with |r| > this to an already-selected one

    Returns:
        list of selected feature column names
    """
    house_col = "Hogwarts House"
    courses = get_courses(df)

    # --- Discriminative power: variance of per-house means ----------------
    house_means = {}
    for house in HOUSES:
        subset = df.loc[df[house_col] == house, courses]
        house_means[house] = mean(subset)

    disc_scores = {}
    for course in courses:
        vals = [house_means[h][course] for h in HOUSES
                if pd.notna(house_means[h].get(course))]
        if len(vals) < 2:
            continue
        grand_mean = sum(vals) / len(vals)
        disc_scores[course] = sum((v - grand_mean) ** 2 for v in vals)

    ranked = sorted(disc_scores, key=disc_scores.get, reverse=True)

    # --- Greedy selection avoiding redundant (highly-correlated) features --
    selected = []
    for feat in ranked:
        if len(selected) >= max_features:
            break
        # check correlation with every already-selected feature
        dominated = False
        for sel in selected:
            r = pearson(df, feat, sel)
            if pd.notna(r) and abs(r) > corr_threshold:
                dominated = True
                break
        if not dominated:
            selected.append(feat)

    return selected


# ──────────────────────── preprocessing ────────────────────────────

def impute_nans(X_df, impute_means=None):
    """
    Replace NaN values with per-column means.

    Arguments:
        X_df: pandas DataFrame of shape (m, n)
        impute_means: dict {col: mean_value}.  If None, compute from X_df.

    Returns:
        (X_filled, impute_means)
    """
    if impute_means is None:
        impute_means = mean(X_df)
    X_filled = X_df.copy()
    for col in X_filled.columns:
        fill_val = impute_means.get(col, 0.0)
        if pd.isna(fill_val):
            fill_val = 0.0
        X_filled[col] = X_filled[col].fillna(fill_val)
    return X_filled, impute_means


def standardize(X_df, means_dict=None, stds_dict=None):
    """
    z-score standardisation: (x - μ) / σ.

    Arguments:
        X_df: pandas DataFrame of shape (m, n)
        means_dict / stds_dict: dicts {col: value}.  If None, compute from
            X_df using custom mean/std from describe.py.

    Returns:
        (X_standardized: np.ndarray,  means_dict,  stds_dict)
    """
    if means_dict is None:
        means_dict = mean(X_df)
    if stds_dict is None:
        stds_dict = std(X_df)
    X_std = X_df.copy()
    for col in X_std.columns:
        m = means_dict[col]
        s = stds_dict[col]
        if pd.isna(s) or s == 0:
            s = 1.0  # avoid division by zero
        X_std[col] = (X_std[col] - m) / s
    return X_std.to_numpy(dtype=float), means_dict, stds_dict


def add_bias(X):
    """Prepend a column of ones (bias / intercept term) to X."""
    return np.column_stack([np.ones(X.shape[0]), X])


# ──────────────────────── optimisers ───────────────────────────────

def train_batch_gd(X, y, lr, epochs):
    """
    Standard (full) batch gradient descent.

    At each epoch the gradient is computed over the *entire* dataset.

    Returns:
        (theta, cost_history)
    """
    m, n = X.shape
    theta = np.zeros(n)
    cost_history = []

    for _ in range(epochs):
        h = sigmoid(X.dot(theta))
        cost_history.append(cost_function(h, y, m))
        grad = compute_gradient(X, h, y, m)
        theta -= lr * grad

    return theta, cost_history


def train_sgd(X, y, lr, epochs):
    """
    Stochastic gradient descent — update θ after *every single sample*.

    Each epoch shuffles the dataset and iterates sample by sample.

    Returns:
        (theta, cost_history)   cost is recorded once per epoch
    """
    m, n = X.shape
    theta = np.zeros(n)
    cost_history = []
    rng = np.random.default_rng(42)

    for _ in range(epochs):
        indices = rng.permutation(m)
        for i in indices:
            xi = X[i:i+1]          # shape (1, n)
            yi = y[i:i+1]          # shape (1,)
            hi = sigmoid(xi.dot(theta))
            grad = compute_gradient(xi, hi, yi, 1)
            theta -= lr * grad
        # record cost over full dataset at end of epoch
        h_full = sigmoid(X.dot(theta))
        cost_history.append(cost_function(h_full, y, m))

    return theta, cost_history


def train_minibatch(X, y, lr, epochs, batch_size=32):
    """
    Mini-batch gradient descent — update θ after each mini-batch.

    Returns:
        (theta, cost_history)   cost is recorded once per epoch
    """
    m, n = X.shape
    theta = np.zeros(n)
    cost_history = []
    rng = np.random.default_rng(42)

    for _ in range(epochs):
        indices = rng.permutation(m)
        for start in range(0, m, batch_size):
            end = min(start + batch_size, m)
            batch_idx = indices[start:end]
            X_b = X[batch_idx]
            y_b = y[batch_idx]
            h_b = sigmoid(X_b.dot(theta))
            grad = compute_gradient(X_b, h_b, y_b, len(batch_idx))
            theta -= lr * grad
        # record cost over full dataset at end of epoch
        h_full = sigmoid(X.dot(theta))
        cost_history.append(cost_function(h_full, y, m))

    return theta, cost_history


OPTIMIZERS = {
    "batch": train_batch_gd,
    "sgd": train_sgd,
    "minibatch": train_minibatch,
}


# ──────────────────────── one-vs-all training ──────────────────────

def train_one_vs_all(X, y_labels, houses, optimizer_name, lr, epochs,
                     batch_size=32):
    """
    Train one binary classifier per house.

    Arguments:
        X:              numpy array (m, n+1) — features + bias
        y_labels:       numpy array (m,) of house-name strings
        houses:         list of house names
        optimizer_name: 'batch', 'sgd', or 'minibatch'
        lr:             learning rate
        epochs:         number of epochs
        batch_size:     mini-batch size (only for 'minibatch')

    Returns:
        dict  {house_name: theta_array}
        dict  {house_name: cost_history_list}
    """
    weights = {}
    histories = {}

    opt_fn = OPTIMIZERS[optimizer_name]

    for house in houses:
        y_bin = (y_labels == house).astype(float)

        if optimizer_name == "minibatch":
            theta, cost_hist = opt_fn(X, y_bin, lr, epochs, batch_size)
        else:
            theta, cost_hist = opt_fn(X, y_bin, lr, epochs)

        weights[house] = theta
        histories[house] = cost_hist

    return weights, histories


def predict_one_vs_all(X, weights, houses):
    """
    Predict house labels using one-vs-all classifiers.

    For each sample, returns the house whose classifier outputs the
    highest probability.

    Arguments:
        X:       numpy array (m, n+1) — features + bias
        weights: dict {house: theta_array}
        houses:  list of house names

    Returns:
        list of predicted house names (length m)
    """
    probs = np.column_stack([sigmoid(X.dot(weights[h])) for h in houses])
    return [houses[i] for i in np.argmax(probs, axis=1)]


# ──────────────────────── accuracy helper ──────────────────────────

def accuracy(y_true, y_pred):
    """Compute accuracy as fraction of correct predictions."""
    correct = sum(1 for a, b in zip(y_true, y_pred) if a == b)
    return correct / len(y_true)


# ──────────────────────── cross-validation ─────────────────────────

def cross_validate(X_df, y_labels, features, optimizer_name, lr, epochs,
                   batch_size=32, k=5):
    """
    k-fold cross-validation.

    Splits the data into k folds, trains on k-1 folds and evaluates on the
    held-out fold.  Repeats k times, rotating the held-out fold each time.

    This is a DIAGNOSTIC tool only — it does not produce the final model.
    It answers: "If I train on subsets of this data, how well do I predict
    the parts I didn't train on?"  A high CV accuracy proves the model
    generalises and is not overfitting.

    Arguments:
        X_df:           pandas DataFrame (m, n_features) — raw feature values
                        (before imputation / standardisation)
        y_labels:       numpy array (m,) of house-name strings
        features:       list of feature column names (for display only)
        optimizer_name: 'batch', 'sgd', or 'minibatch'
        lr:             learning rate
        epochs:         number of epochs
        batch_size:     mini-batch size
        k:              number of folds (default 5)

    Returns:
        list of per-fold accuracies
    """
    rng = np.random.default_rng(42)
    indices = rng.permutation(len(y_labels))
    fold_size = len(y_labels) // k
    fold_accs = []

    print(f"\n── {k}-fold cross-validation ──")

    for fold in range(k):
        # --- Split into train / validation --------------------------------
        start = fold * fold_size
        end = start + fold_size if fold < k - 1 else len(y_labels)
        val_idx = indices[start:end]
        train_idx = np.concatenate([indices[:start], indices[end:]])

        X_tr = X_df.iloc[train_idx].reset_index(drop=True)
        y_tr = y_labels[train_idx]
        X_va = X_df.iloc[val_idx].reset_index(drop=True)
        y_va = y_labels[val_idx]

        # --- Preprocess training fold (compute stats from train only) -----
        X_tr_filled, imp_means = impute_nans(X_tr)
        X_tr_std, tr_means, tr_stds = standardize(X_tr_filled)
        X_tr_b = add_bias(X_tr_std)

        # --- Preprocess validation fold (using TRAINING stats) ------------
        X_va_filled = X_va.copy()
        for col in X_va_filled.columns:
            X_va_filled[col] = X_va_filled[col].fillna(
                imp_means.get(col, 0.0)
            )
        X_va_std = X_va_filled.copy()
        for col in X_va_std.columns:
            mm = tr_means[col]
            ss = tr_stds[col]
            if pd.isna(ss) or ss == 0:
                ss = 1.0
            X_va_std[col] = (X_va_std[col] - mm) / ss
        X_va_b = add_bias(X_va_std.to_numpy(dtype=float))

        # --- Train and evaluate -------------------------------------------
        w, _ = train_one_vs_all(
            X_tr_b, y_tr, HOUSES, optimizer_name, lr, epochs, batch_size
        )
        preds = predict_one_vs_all(X_va_b, w, HOUSES)
        acc = accuracy(y_va, preds)
        fold_accs.append(acc)
        print(f"  Fold {fold + 1}: accuracy = {acc:.4%}")

    mean_acc = sum(fold_accs) / len(fold_accs)
    min_acc = min(fold_accs)
    print(f"\n  Mean CV accuracy: {mean_acc:.4%}")
    print(f"  Min  CV accuracy: {min_acc:.4%}")
    print(f"  {'✅ PASS' if mean_acc >= 0.98 else '❌ FAIL'} "
          f"(threshold ≥ 98%)")

    return fold_accs


# ──────────────────────────── main ─────────────────────────────────

def main():
    args = get_args()

    # ---- Load dataset ---------------------------------------------------
    if not args.dataset.is_file():
        print(f"Error: dataset file '{args.dataset}' not found.", file=sys.stderr)
        sys.exit(1)
    try:
        df = pd.read_csv(args.dataset)
    except Exception as e:
        print(f"Error reading dataset: {e}", file=sys.stderr)
        sys.exit(1)

    house_col = "Hogwarts House"
    if house_col not in df.columns:
        print(f"Error: '{house_col}' column not found in dataset.",
              file=sys.stderr)
        sys.exit(1)

    # ---- Feature selection -----------------------------------------------
    if args.auto_select:
        features = auto_select_features(df)
        print(f"Auto-selected features ({len(features)}): {features}")
    else:
        features = DEFAULT_FEATURES
        # Validate that all hard-coded features exist in the dataset
        missing = [f for f in features if f not in df.columns]
        if missing:
            print(f"Error: features not found in dataset: {missing}",
                  file=sys.stderr)
            sys.exit(1)
        print(f"Using default features ({len(features)}): {features}")

    # ---- Extract features and labels -------------------------------------
    X_df = df[features].copy()
    y_labels = df[house_col].to_numpy()

    # Drop any rows where the label is missing
    valid = pd.notna(y_labels)
    X_df = X_df.loc[valid].reset_index(drop=True)
    y_labels = y_labels[valid]

    # ---- Impute NaN values -----------------------------------------------
    X_df, imputation_means = impute_nans(X_df)

    # ---- Standardise features --------------------------------------------
    X_np, std_means, std_stds = standardize(X_df)

    # ---- Add bias column -------------------------------------------------
    X_np = add_bias(X_np)

    # ---- Cross-validation (diagnostic, optional) -------------------------
    if args.cross_validate:
        cross_validate(
            X_df.copy(), y_labels, features,
            optimizer_name=args.optimizer,
            lr=args.lr,
            epochs=args.epochs,
            batch_size=args.batch_size,
        )

    # ---- Train one-vs-all ------------------------------------------------
    print(f"\nTraining ({args.optimizer} GD, lr={args.lr}, "
          f"epochs={args.epochs}"
          + (f", batch_size={args.batch_size}"
             if args.optimizer == "minibatch" else "")
          + ") …")

    weights, cost_histories = train_one_vs_all(
        X_np, y_labels, HOUSES,
        optimizer_name=args.optimizer,
        lr=args.lr,
        epochs=args.epochs,
        batch_size=args.batch_size,
    )

    # ---- Training summary ------------------------------------------------
    print("\n── Training results ──")
    for house in HOUSES:
        final_cost = cost_histories[house][-1]
        print(f"  {house:15s}  final cost = {final_cost:.6f}")

    y_pred = predict_one_vs_all(X_np, weights, HOUSES)
    acc = accuracy(y_labels, y_pred)
    print(f"\n  Training accuracy: {acc:.4%}")

    # ---- Save weights ----------------------------------------------------
    payload = {
        "features": features,
        "standardization": {
            "means": {k: float(v) for k, v in std_means.items()},
            "stds":  {k: float(v) for k, v in std_stds.items()},
        },
        "imputation_means": {k: float(v) for k, v in imputation_means.items()},
        "weights": {h: weights[h].tolist() for h in HOUSES},
        "hyperparameters": {
            "optimizer": args.optimizer,
            "learning_rate": args.lr,
            "epochs": args.epochs,
            **({"batch_size": args.batch_size}
               if args.optimizer == "minibatch" else {}),
        },
    }
    args.output.write_text(json.dumps(payload, indent=2))
    print(f"\n  Weights saved to {args.output}")


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nInterrupted by user. Exiting...")
        sys.exit(0)
