#!/usr/bin/env python3
"""
Author: doriani <doriani@student.42roma.it>
Author: gmartin <gmartin@student.42roma.it>
Date: 2025-10-29
Purpose: Plots a scatter matrix or a pair plot from a Hogwarts houses dataset.
Description:
    Plots a scatter matrix or a pair plot grid from a CSV dataset.
    The plot should help to answer the following question:

        From this visualization, which features are
        you going to use for your logistic regression?

    See also V2_3_pairplot_walkthrough.ipynb for a step-by-step walkthrough.
"""
import argparse
from pathlib import Path
import pandas as pd
import math
import matplotlib.pyplot as plt
from histogram import freedman_diaconis_bins
from plot_utilities import (get_palette, get_courses, get_houses,
                            get_pairs, get_selected_pairs)


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

    parser.add_argument('-p',
                        '--plot-type',
                        metavar='TYPE',
                        help='Type of plot to generate: "panel" or "grid"',
                        type=str,
                        choices=['panel', 'grid'],
                        default='grid',
                        )
    parser.add_argument('-s',
                        '--save',
                        type=Path,
                        default=None,
                        help='Save the figure to this path (PNG).')

    return parser.parse_args()


def plot_matrix(df, houses, house_column, pairs,
                palette: list = None, save_path: str = None):
    """Plot a panel of selected pairs."""

    def scatter_panel(ax, xcol, ycol, r):
        """Plot a scatter panel for two features colored by house."""

        for h in houses:
            sub = df.loc[df[house_column] == h, [xcol, ycol]].dropna()
            if not sub.empty:
                ax.scatter(sub[xcol], sub[ycol], s=18, alpha=0.7,
                           label=h, color=palette[h])
        ax.set_xlabel(xcol)
        ax.set_ylabel(ycol)
        ax.set_title(f"{xcol} vs {ycol}\n r={r:+.3f}", pad=6)

    # prepare palette
    palette = get_palette(houses, palette)

    # select features
    selected_features = get_selected_pairs(pairs)

    # prepare subplots grid
    n = len(selected_features)
    ncols = 2
    nrows = math.ceil(n / ncols)
    fig, axes = plt.subplots(nrows=nrows, ncols=ncols,
                             figsize=(11, 1 + 3.4 * nrows))

    # flatten axes array for easy iteration
    axes = axes.flatten() if n > 1 else [axes]

    # plot each pair
    for ax, (xcol, ycol, r) in zip(axes, selected_features):
        scatter_panel(ax, xcol, ycol, r)

    # fill extra axes if any
    for ax in axes[n:]:
        ax.axis("off")

    # shared legend
    handles, labels = axes[0].get_legend_handles_labels()
    fig.legend(handles, labels, loc="upper right", frameon=True, ncols=1,
               bbox_to_anchor=(1, 0.98))

    # adjust layout
    plt.tight_layout(rect=[0, 0, 0.88, 1])
    if save_path:
        plt.savefig(save_path, dpi=150, bbox_inches="tight")
    plt.show()


def plot_grid(df, houses, house_column, pairs,
              alpha_hist=0.5, s_scatter=14,
              palette: list = None, save_path: str = None):
    """
    Plot a pair grid with histograms on the diagonal
    and scatter plots off-diagonal.
    """

    # prepare palette
    palette = get_palette(houses, palette)

    # Pick ~4 features from the strongest pairs to build a grid
    selected_features = []
    for a, b, r in pairs:
        for f in (a, b):
            if f not in selected_features:
                selected_features.append(f)
        if len(selected_features) >= 4:
            break

    # prepare subplots grid
    n = len(selected_features)
    fig, axes = plt.subplots(nrows=n, ncols=n, figsize=(3.2*n, 3.2*n))

    # plot each cell in the grid
    for i, yi in enumerate(selected_features):
        for j, xj in enumerate(selected_features):
            ax = axes[i, j]
            if i == j:
                # diagonal: overlaid histograms per house
                for h in houses:
                    vals = df.loc[df[house_column] == h, yi].dropna()
                    bins = freedman_diaconis_bins(vals)
                    if not vals.empty:
                        ax.hist(vals, bins=bins, alpha=alpha_hist,
                                edgecolor="black", label=h if j == 0 else None,
                                density=False, color=palette[h])
            else:
                # off-diagonal: scatter per house
                for h in houses:
                    sub = df.loc[df[house_column] == h, [xj, yi]].dropna()
                    if not sub.empty:
                        ax.scatter(sub[xj], sub[yi], s=s_scatter,
                                   alpha=0.7, color=palette[h],
                                   label=h if (i == 0 and j == 1) else None)
            # setting axis labels
            ax.set_ylabel(yi if j == 0 else "")
            ax.set_xlabel(xj if i == n - 1 else "")
            # light grid for readability
            ax.grid(alpha=0.25)

    # one shared legend outside
    handles, labels = axes[0, 0].get_legend_handles_labels()
    if not handles:
        # fetch from any axis that has labels
        for row in axes:
            for ax in row:
                hls = ax.get_legend_handles_labels()
                if hls[0]:
                    handles, labels = hls
                    break
            if handles:
                break
    if handles:
        fig.legend(handles, labels, loc="upper right",
                   frameon=True, bbox_to_anchor=(1, 0.98))

    plt.tight_layout(rect=[0, 0, 0.88, 1])
    if save_path:
        plt.savefig(save_path, dpi=150, bbox_inches="tight")
    plt.show()


def main():
    """Main function"""

    # Get command-line arguments and read dataset
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
    plot_type = args.plot_type
    save_path = args.save

    # define houses
    houses = get_houses(df)

    # define house column
    house_column = "Hogwarts House"

    # define courses
    courses = get_courses(df)

    # define course pairs and their Pearson correlation
    try:
        pairs = get_pairs(df, courses)
    except ValueError as ve:
        print(f"Error: {ve}")
        exit(1)

    # print top 6 correlated courses
    print("----- Top 6 correlated courses -----")
    for a, b, r in pairs[:6]:
        print(f"  {a:35s} vs {b:35s}  r={r:+.4f}  |r|={abs(r):.4f}")

    # print top 6 correlated courses
    print("\n----- Bottom 6 correlated courses -----")
    for a, b, r in pairs[-6:]:
        print(f"  {a:35s} vs {b:35s}  r={r:+.4f}  |r|={abs(r):.4f}")

    # plot according to selected type
    if plot_type == 'panel':
        plot_matrix(df, houses, house_column, pairs, save_path=save_path)
    elif plot_type == 'grid':
        plot_grid(df, houses, house_column, pairs, save_path=save_path)
    else:
        print(f"Error: Unknown plot type '{plot_type}'")
        exit(1)


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print('\nInterrupted by user. Exiting...')
        exit(0)
