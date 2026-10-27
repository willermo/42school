#!/usr/bin/env python3
"""
Author: doriani <doriani@student.42roma.it>
Author: gmartin <gmartin@student.42roma.it>
Date: 2025-10-21
Purpose: Plots a histogram from a specified Hogwarts houses dataset.
Description:
    Plots a histogram from a CSV dataset that answers the following question:

        Which Hogwarts course has a homogeneous
        score distribution between all four houses?

    See also V2_1_histogram_walkthrough.ipynb for a step-by-step walkthrough.
"""
from typing import Iterable
import argparse
from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

from describe import (mean, variance, skewness, interquartile_range,
                      range_stat, count, numeric_dataframe)


def get_args():
    """Get command-line arguments"""

    parser = argparse.ArgumentParser(
        description='Plots a histogram from a Hogwarts houses CSV dataset',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)

    parser.add_argument('dataset',
                        metavar='FILE',
                        help='The csv file containing the dataset',
                        type=Path,
                        nargs='?',
                        default='dataset_train.csv')

    return parser.parse_args()


def house_stats(
        df: pd.DataFrame,
        houses,
        course_columns: Iterable[str],
        house_col: str = "Hogwarts House",
) -> pd.DataFrame:
    """Calculate statistics for each Hogwarts house in the dataset."""
    course_columns = list(course_columns)

    # Keep only numeric course columns
    num_cols = numeric_dataframe(df[course_columns]).columns.tolist()
    if len(num_cols) != len(course_columns):
        bad = [c for c in course_columns if c not in num_cols]
        raise ValueError(f"Non-numeric course columns: {bad}")

    # ---- Compute metrics per house ----
    stats_per_house = {}
    for house in houses:
        subset = df.loc[df[house_col] == house, num_cols]
        stats_per_house[house] = {
            "count": count(subset),
            "mean": mean(subset),
            "variance": variance(subset),
            "skewness": skewness(subset),
            "iqr": interquartile_range(subset),
        }

    # ---- Assemble wide table: MultiIndex (house, metric) x course ----
    table = pd.concat(
        {h: pd.DataFrame(mets).T for h, mets in stats_per_house.items()}
    )

    table.index.set_names(["house", "metric"], inplace=True)
    table = table.loc[:, num_cols]  # keep the requested order

    return table


def freedman_diaconis_bins(values: np.ndarray, min_bins: int = 8) -> int:
    """Calculate number of histogram bins using Freedman-Diaconis rule."""
    vals = values[~np.isnan(values)]
    if len(vals) < 2:
        return min_bins

    # Use interquartile_range from describe.py by passing a 1-column DataFrame
    df = pd.DataFrame({'_vals': vals})
    iqr_val = interquartile_range(df)['_vals']

    if pd.isna(iqr_val) or iqr_val <= 0:
        return max(min_bins, min(50, int(np.sqrt(len(vals))) or 1))
    width = 2 * iqr_val / (len(vals) ** (1/3))
    if width <= 0:
        return max(min_bins, 10)
    bins = int(np.ceil((vals.max() - vals.min()) / width))
    return max(min_bins, min(bins, 200))


def plot_course_histograms(df, houses, course, house_col="Hogwarts House"):
    """Plot histograms of course scores by house."""
    all_vals = df[course].dropna().to_numpy()
    if len(all_vals) == 0:
        raise ValueError(f"No data available for course '{course}'")
    xmin, xmax = float(np.min(all_vals)), float(np.max(all_vals))
    bins = freedman_diaconis_bins(all_vals)
    plt.figure(figsize=(8, 5))
    for h in houses:
        vals = df.loc[df[house_col] == h, course].dropna().to_numpy()
        plt.hist(vals, bins=bins, range=(xmin, xmax),
                 alpha=0.5, density=True, label=h)
    plt.title(f"{course} — distributions by house (FD bins={bins})")
    plt.xlabel("Score")
    plt.ylabel("Density")
    plt.legend()
    plt.tight_layout()
    plt.show()


def main():
    """Main function"""

    args = get_args()
    dataset_file = args.dataset
    if not dataset_file.is_file():
        print(f"Error: Dataset file '{dataset_file}' not found.")
        exit(1)
    try:
        dataset = pd.read_csv(dataset_file)
    except Exception as e:
        print(f"Error: Failed to read dataset file '{dataset_file}': {e}")
        exit(1)

    # define course columns
    non_course_cols = {"Index", "Hogwarts House", "First Name", "Last Name",
                       "Birthday", "Best Hand"}
    course_cols = [c for c in dataset.columns if c not in non_course_cols]

    # define house column
    house_column = "Hogwarts House"

    # define houses
    HOUSE_ORDER = ["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"]
    houses_present = dataset[house_column].dropna().unique()
    houses = [h for h in HOUSE_ORDER if h in houses_present]

    try:
        stats = house_stats(dataset, houses, course_cols, house_column)
    except ValueError as ve:
        print(f"Error: {ve}")
        exit(1)

    # Apply counts threshold and set up mask
    MIN_COUNT_PER_HOUSE = 10
    counts = stats.xs("count", level="metric")
    courses_mask = (counts >= MIN_COUNT_PER_HOUSE).all(axis=0)

    # Check if any courses meet the minimum count requirement
    if not courses_mask.any():
        print(f"No courses meet MIN_COUNT_PER_HOUSE={MIN_COUNT_PER_HOUSE} "
              "for all houses.")
        return

    # Pull the table for a metric across houses (rows=houses, cols=courses)
    means = stats.xs("mean", level="metric").loc[:, courses_mask]
    vars_ = stats.xs("variance", level="metric").loc[:, courses_mask]
    skews = stats.xs("skewness", level="metric").loc[:, courses_mask]
    iqrs = stats.xs("iqr", level="metric").loc[:, courses_mask]

    # Compute a robust "difference across houses" per course
    mean_range = pd.Series(range_stat(means)).astype(float)
    var_range = pd.Series(range_stat(vars_)).astype(float)
    skew_range = pd.Series(range_stat(skews)).astype(float)
    iqr_range = pd.Series(range_stat(iqrs)).astype(float)

    # Rank courses by their homogeneity (smaller range = more homogeneous)
    mean_rank = mean_range.rank(method="average", ascending=True)
    var_rank = var_range.rank(method="average", ascending=True)
    skew_rank = skew_range.rank(method="average", ascending=True)
    iqr_rank = iqr_range.rank(method="average", ascending=True)

    # Combine ranks into a single homogeneity score
    WEIGHT_MEAN = 5.0
    WEIGHT_IQR = 5.0
    WEIGHT_SKEW = 2.0
    WEIGHT_VAR = 1.0
    homog_score = (WEIGHT_MEAN * mean_rank +
                   WEIGHT_IQR * iqr_rank +
                   WEIGHT_VAR * var_rank +
                   WEIGHT_SKEW * skew_rank)
    homog_score.sort_values(inplace=True)

    # Output results
    print("Top-5 homogeneous courses:")
    print(homog_score.head(5))

    # Plot histogram for the most homogeneous course
    most_homogeneous_course = homog_score.index[0]
    plot_course_histograms(dataset, houses,
                           most_homogeneous_course, house_column)


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print('\nInterrupted by user. Exiting...')
        exit(0)
