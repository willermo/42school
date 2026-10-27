#!/usr/bin/env python3
"""
Author: doriani <doriani@student.42roma.it>
Author: gmartin <gmartin@student.42roma.it>
Date: 2025-10-29
Purpose: Plots a scatter plot from a specified Hogwarts houses dataset.
Description:
    Plots a scatterplot from a CSV dataset that answers the following question:

        What are the two features that are similar?

    See also V2_2_scatter_walkthrough.ipynb for a step-by-step walkthrough.
"""
import argparse
from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt

from describe import numeric_dataframe
from plot_utilities import pearson, pair_combinations


def get_args():
    """Get command-line arguments"""

    parser = argparse.ArgumentParser(
        description='Plots a scatter plot from a Hogwarts houses CSV dataset',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)

    parser.add_argument('dataset',
                        metavar='FILE',
                        help='The csv file containing the dataset',
                        type=Path,
                        nargs='?',
                        default='dataset_train.csv')

    return parser.parse_args()


def plot_scatter(df: pd.DataFrame, pairs: list,
                 house_order: list,
                 house_column: str = "Hogwarts House",
                 palette: list = None):
    """Plot scatter plots for given course pairs colored by Hogwarts house."""
    if palette is None:
        palette = []
    if len(palette) < len(house_order):
        additional_colors = plt.get_cmap('tab10').colors
        for i in range(len(house_order) - len(palette)):
            palette.append(additional_colors[i % len(additional_colors)])
    palette = {h: palette[i] for i, h in enumerate(house_order)}
    top_x, top_y, rbest = pairs[0]

    plt.figure(figsize=(9, 5))
    for h in [h for h in house_order
              if h in df[house_column].dropna().unique()]:
        sub = df.loc[df[house_column] == h, [top_x, top_y]].dropna()
        plt.scatter(sub[top_x], sub[top_y], s=20, alpha=0.7, label=h,
                    color=palette[h])

    plt.xlabel(top_x)
    plt.ylabel(top_y)
    plt.title(f"Most similar features: {top_x} vs {top_y}  (r={rbest:+.3f})")
    plt.legend(frameon=False)
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
        df = pd.read_csv(dataset_file)
    except Exception as e:
        print(f"Error: Failed to read dataset file '{dataset_file}': {e}")
        exit(1)

    # define house column
    house_column = "Hogwarts House"

    # define houses
    house_order = ["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"]
    houses_present = df[house_column].dropna().unique()
    houses = [h for h in house_order if h in houses_present]

    # define courses
    non_course = {"Index", "Hogwarts House", "First Name",
                  "Last Name", "Birthday", "Best Hand"}
    courses = numeric_dataframe(
        df[[c for c in df.columns if c not in non_course]]).columns.tolist()

    # define course pairs and compute Pearson correlation
    pairs = []
    for a, b in pair_combinations(courses):
        r = pearson(df, a, b)
        if pd.notna(r):
            pairs.append((a, b, r))
    if not pairs:
        print("No valid feature pairs with computable correlation were found.")
        return  # or exit(1)

    # sort pairs by absolute correlation strength
    pairs.sort(key=lambda t: abs(t[2]), reverse=True)

    # print top 5 correlated courses
    print("----- Top 5 correlated courses -----")
    for a, b, r in pairs[:5]:
        print(f'"{a}" / "{b}"  r = {r:+.6f}  |r| = {abs(r):.6f}')
    plot_scatter(df, pairs, houses, house_column)


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print('\nInterrupted by user. Exiting...')
        exit(0)
