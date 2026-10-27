#!/usr/bin/env python3
"""
Author: doriani <doriani@student.42roma.it>
Author: gmartin <gmartin@student.42roma.it>
Date: 2025-10-29
Purpose: Predict Hogwarts houses using a trained logistic regression model.
Description:
    Reads a test dataset and a weights file produced by logreg_train.py,
    applies the same preprocessing pipeline (NaN imputation + z-score
    standardisation using the *training* statistics), and outputs
    houses.csv with predicted house labels.

    See also V3_logistic_regression_walkthrough.ipynb for a step-by-step
    walkthrough.
"""
import argparse
import json
import sys
from pathlib import Path

import numpy as np
import pandas as pd

from math_utils import sigmoid


# ──────────────────────────── constants ────────────────────────────

HOUSES = ["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"]


# ──────────────────────────── arg parsing ──────────────────────────

def get_args():
    """Parse command-line arguments."""
    p = argparse.ArgumentParser(
        description="Predict Hogwarts houses using a trained logistic "
                    "regression model",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    p.add_argument("dataset", metavar="FILE", type=Path,
                   help="CSV test dataset (e.g. dataset_test.csv)")
    p.add_argument("weights", metavar="WEIGHTS", type=Path,
                   help="JSON weights file produced by logreg_train.py")
    p.add_argument("--output", "-o", type=Path, default=Path("houses.csv"),
                   help="Output path for predictions")
    return p.parse_args()


# ──────────────────────── preprocessing ────────────────────────────

def impute_nans(X_df, imputation_means):
    """Replace NaN values with training-set means."""
    X_filled = X_df.copy()
    for col in X_filled.columns:
        fill_val = imputation_means.get(col, 0.0)
        X_filled[col] = X_filled[col].fillna(fill_val)
    return X_filled


def standardize(X_df, means_dict, stds_dict):
    """z-score standardisation using training-set statistics."""
    X_std = X_df.copy()
    for col in X_std.columns:
        m = means_dict[col]
        s = stds_dict[col]
        if s == 0:
            s = 1.0
        X_std[col] = (X_std[col] - m) / s
    return X_std.to_numpy(dtype=float)


def add_bias(X):
    """Prepend a column of ones (bias / intercept term) to X."""
    return np.column_stack([np.ones(X.shape[0]), X])


# ──────────────────────── prediction ───────────────────────────────

def predict_one_vs_all(X, weights, houses):
    """
    Predict house labels using one-vs-all classifiers.

    For each sample, returns the house whose classifier outputs the
    highest probability.
    """
    probs = np.column_stack([sigmoid(X.dot(np.array(weights[h])))
                             for h in houses])
    return [houses[i] for i in np.argmax(probs, axis=1)]


# ──────────────────────────── main ─────────────────────────────────

def main():
    args = get_args()

    # ---- Load weights ----------------------------------------------------
    if not args.weights.is_file():
        print(f"Error: weights file '{args.weights}' not found.",
              file=sys.stderr)
        sys.exit(1)
    try:
        payload = json.loads(args.weights.read_text())
    except Exception as e:
        print(f"Error reading weights file: {e}", file=sys.stderr)
        sys.exit(1)

    features = payload["features"]
    std_means = payload["standardization"]["means"]
    std_stds = payload["standardization"]["stds"]
    imputation_means = payload["imputation_means"]
    weights = payload["weights"]

    # ---- Load dataset ----------------------------------------------------
    if not args.dataset.is_file():
        print(f"Error: dataset file '{args.dataset}' not found.",
              file=sys.stderr)
        sys.exit(1)
    try:
        df = pd.read_csv(args.dataset)
    except Exception as e:
        print(f"Error reading dataset: {e}", file=sys.stderr)
        sys.exit(1)

    # Validate features exist in test set
    missing = [f for f in features if f not in df.columns]
    if missing:
        print(f"Error: features not found in test dataset: {missing}",
              file=sys.stderr)
        sys.exit(1)

    # ---- Extract features ------------------------------------------------
    X_df = df[features].copy()

    # ---- Impute NaN values (using training means) -------------------------
    X_df = impute_nans(X_df, imputation_means)

    # ---- Standardise (using training statistics) --------------------------
    X_np = standardize(X_df, std_means, std_stds)

    # ---- Add bias column --------------------------------------------------
    X_np = add_bias(X_np)

    # ---- Predict ----------------------------------------------------------
    predictions = predict_one_vs_all(X_np, weights, HOUSES)

    # ---- Write houses.csv -------------------------------------------------
    result = pd.DataFrame({
        "Index": range(len(predictions)),
        "Hogwarts House": predictions,
    })
    result.to_csv(args.output, index=False)
    print(f"Predictions saved to {args.output}  ({len(predictions)} rows)")


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nInterrupted by user. Exiting...")
        sys.exit(0)
