#!/usr/bin/env python3
"""
Author: doriani <doriani@student.42roma.it>
Author: gmartin <gmartin@student.42roma.it>
Date: 2025-10-29
Purpose: Evaluate predictions against ground truth using sklearn's accuracy_score.
Description:
    This script mirrors the evaluator's process: compare houses.csv predictions
    against a truth file using scikit-learn's accuracy_score.

    Usage:
        # Compare predictions against a truth file
        python3 evaluate.py houses.csv truth.csv

        # Self-test: train, predict on training set, evaluate
        python3 logreg_train.py dataset_train.csv
        python3 logreg_predict.py dataset_train.csv weights.json -o houses_train.csv
        python3 evaluate.py houses_train.csv dataset_train.csv
"""
import argparse
import sys
from pathlib import Path

import pandas as pd
from sklearn.metrics import accuracy_score, classification_report


def get_args():
    """Parse command-line arguments."""
    p = argparse.ArgumentParser(
        description="Evaluate Hogwarts house predictions using sklearn",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    p.add_argument("predictions", metavar="PREDICTIONS", type=Path,
                   help="CSV file with predicted houses (e.g. houses.csv)")
    p.add_argument("truth", metavar="TRUTH", type=Path,
                   help="CSV file with true labels (must have 'Hogwarts House' "
                        "column)")
    return p.parse_args()


def main():
    args = get_args()

    # ---- Load predictions ------------------------------------------------
    if not args.predictions.is_file():
        print(f"Error: predictions file '{args.predictions}' not found.",
              file=sys.stderr)
        sys.exit(1)
    pred_df = pd.read_csv(args.predictions)
    if "Hogwarts House" not in pred_df.columns:
        print("Error: predictions file must have 'Hogwarts House' column.",
              file=sys.stderr)
        sys.exit(1)

    # ---- Load truth ------------------------------------------------------
    if not args.truth.is_file():
        print(f"Error: truth file '{args.truth}' not found.", file=sys.stderr)
        sys.exit(1)
    truth_df = pd.read_csv(args.truth)
    if "Hogwarts House" not in truth_df.columns:
        print("Error: truth file must have 'Hogwarts House' column.",
              file=sys.stderr)
        sys.exit(1)

    # ---- Extract labels --------------------------------------------------
    y_pred = pred_df["Hogwarts House"].values
    y_true = truth_df["Hogwarts House"].values

    # Handle size mismatch
    if len(y_pred) != len(y_true):
        print(f"Warning: prediction count ({len(y_pred)}) != truth count "
              f"({len(y_true)}). Comparing first {min(len(y_pred), len(y_true))} rows.",
              file=sys.stderr)
        n = min(len(y_pred), len(y_true))
        y_pred = y_pred[:n]
        y_true = y_true[:n]

    # Skip rows where truth is NaN (e.g. dataset_test.csv has all NaN)
    valid = pd.notna(y_true)
    if valid.sum() == 0:
        print("Error: truth file has no valid (non-NaN) house labels.",
              file=sys.stderr)
        sys.exit(1)
    if valid.sum() < len(y_true):
        print(f"Note: skipping {(~valid).sum()} rows with NaN truth labels.")
    y_pred = y_pred[valid]
    y_true = y_true[valid]

    # ---- Evaluate --------------------------------------------------------
    acc = accuracy_score(y_true, y_pred)
    print(f"\n  Accuracy (sklearn): {acc:.4%}")
    print(f"  Threshold (≥98%):  {'✅ PASS' if acc >= 0.98 else '❌ FAIL'}")
    print(f"  Samples evaluated: {len(y_true)}")

    print(f"\n{classification_report(y_true, y_pred)}")


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nInterrupted by user. Exiting...")
        sys.exit(0)
