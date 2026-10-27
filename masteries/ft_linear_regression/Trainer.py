#!/usr/bin/env python3
"""
Author: doriani <doriani@student.42roma.it>
Date: 2025-10-21
Purpose: Train a linear regression model using gradient descent.
Description:
    This script implements gradient descent to fit a linear regression model
    to a dataset provided in a CSV file. It includes options to plot the data
    and the regression line, as well as to display the precision of the model
    on the training data.
    If no dataset file is provided, it defaults to 'data.csv'.
"""

from matplotlib import pyplot as plt
import numpy as np
import pandas as pd
import argparse
from pathlib import Path


def get_args():
    """Get command-line arguments"""

    parser = argparse.ArgumentParser(
        description='Train a linear regression model using gradient descent',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)

    parser.add_argument('dataset',
                        metavar='FILE',
                        help='The csv file containing the dataset',
                        type=Path,
                        nargs='?',
                        default='data.csv')

    parser.add_argument('-l', '--learning-rate',
                        metavar='float',
                        help='The learning rate for gradient descent',
                        type=float,
                        default=0.05)

    parser.add_argument('-m', '--max-iterations',
                        metavar='int',
                        help='The maximum number of iterations \
                        for gradient descent',
                        type=int,
                        default=1000000)

    parser.add_argument('--x-index',
                        metavar='str',
                        help='The name of the column to be used as x feature',
                        type=str,
                        default='km')

    parser.add_argument('--y-index',
                        metavar='str',
                        help='The name of the column to be used as y feature',
                        type=str,
                        default='price')

    parser.add_argument('--x-label',
                        metavar='str',
                        help='The label for the x axis in plots',
                        type=str,
                        default='kilometers')

    parser.add_argument('--y-label',
                        metavar='str',
                        help='The label for the y axis in plots',
                        type=str,
                        default='price')

    parser.add_argument('-p', '--plot',
                        action='store_true',
                        help='Plot the scattered data and the regression line')

    parser.add_argument('-s', '--show-algorithm-precision',
                        action='store_true',
                        help='Show the precision of the algorithm \
                        on the training data')

    return parser.parse_args()


def gradient_descent(
        data,
        learning_rate=0.05,
        w0=0.0,
        b0=0.0,
        x_col='km',
        y_col='price',
        max_iters=100000,
        tol=1e-10,
        normalize=True,
        grad_clip=1e6,  # clip gradient norm to avoid explosions
        backoff=0.5,  # halve lr if cost gets worse/NaN
        patience=10,  # allow a few backoffs before giving up
        track_history=False
):
    """
    Gradient descent for y ≈ w*x + b.

    If normalize=True (default), we optimize on z = (x - mu)/sigma internally
    for stability and then return (w,b) in the *original* x units:

      w_real = w_norm / sigma
      b_real = b_norm - (w_norm * mu / sigma)

    Returns (w_final, b_final, history or None).
    """

    # Validate that required columns exist
    if x_col not in data.columns:
        raise ValueError(
            f"Column '{x_col}' not found in DataFrame. \
            Available columns: {list(data.columns)}")
    if y_col not in data.columns:
        raise ValueError(
            f"Column '{y_col}' not found in DataFrame. \
            Available columns: {list(data.columns)}")

    x = data[x_col].to_numpy(dtype=float)
    y = data[y_col].to_numpy(dtype=float)
    m = x.shape[0]

    # Validate that we have data
    if m == 0:
        raise ValueError("DataFrame is empty after filtering columns")

    # x feature normalization
    if normalize:
        mu = x.mean()
        sigma = x.std()
        if sigma == 0:
            sigma = 1.0
        z = (x - mu) / sigma
        # map (w_real, b_real) to normalized space initial (w,b)
        # initially w0,b0 are in real space; convert to normalized params:
        w = w0 * sigma
        b = b0 + w0 * mu
        x_used = z
    else:
        mu = 0.0
        sigma = 1.0
        z = x  # not used
        w = float(w0)
        b = float(b0)
        x_used = x

    def cost_on_used(wc, bc):
        err = (wc * x_used + bc) - y
        return 0.5 * np.mean(err * err)

    def grads_on_used(wc, bc):
        err = (wc * x_used + bc) - y
        dj_dw = (1.0 / m) * np.dot(err, x_used)
        dj_db = (1.0 / m) * np.sum(err)
        return dj_dw, dj_db

    J_prev = np.inf
    lr = float(learning_rate)
    backoffs_left = patience

    J_hist = []
    wb_hist = []
    iterations = 0

    for it in range(max_iters):
        iterations += 1
        dj_dw, dj_db = grads_on_used(w, b)

        # Gradient clipping (by L2 norm)
        gnorm = np.hypot(dj_dw, dj_db)
        if np.isfinite(gnorm) and gnorm > grad_clip:
            scale = grad_clip / gnorm
            dj_dw *= scale
            dj_db *= scale

        w_next = w - lr * dj_dw
        b_next = b - lr * dj_db

        J_next = cost_on_used(w_next, b_next)

        # If cost is NaN/Inf or increased significantly,
        # back off LR and retry this step
        if not np.isfinite(J_next) or J_next > J_prev * 1.1:
            if backoffs_left <= 0:
                # give up and return what we have transformed back
                break
            lr *= backoff
            backoffs_left -= 1
            continue

        # Accept step
        if track_history:
            J_hist.append(J_next)
            wb_hist.append((w_next, b_next))

        # Convergence on cost improvement
        if abs(J_prev - J_next) < tol:
            w, b = w_next, b_next
            J_prev = J_next
            break

        w, b = w_next, b_next
        J_prev = J_next

    # Map back to *original* x units if we normalized internally
    if normalize:
        # w_real = w_norm / sigma
        # b_real = b_norm - (w_norm * mu / sigma)
        w_real = w / sigma
        b_real = b - (w * mu / sigma)
    else:
        w_real, b_real = w, b

    history = None
    if track_history:
        history = {'J': J_hist, 'params_used_space': wb_hist}

    return w_real, b_real, iterations, history


def plot_multiple_cost_histories(histories, labels=None,
                                 title="Cost function over iterations"):
    """
    Plot multiple cost histories on a single figure for comparison.

    Parameters:
        histories : list of history dicts (from gradient_descent)
        labels    : list of str, same length as histories (optional)
        title     : str, chart title
    """
    if labels is None:
        labels = [f"Run {i + 1}" for i in range(len(histories))]

    fig, ax = plt.subplots(figsize=(9, 5))

    for hist, label in zip(histories, labels):
        if hist is None or 'J' not in hist or len(hist['J']) == 0:
            print(f"⚠️ Skipping {label}: no cost history.")
            continue

        J_vals = np.array(hist['J'])
        iters = np.arange(1, len(J_vals) + 1)
        ax.plot(iters, J_vals, lw=2, label=label)

    ax.set_xlabel('Iteration')
    ax.set_ylabel('Cost J(w,b)')
    ax.set_title(title)
    ax.grid(True, linestyle='--', alpha=0.5)
    ax.legend(loc='best')
    plt.tight_layout()
    plt.show()


def plot_dataset_and_regression_line(data: pd.DataFrame, lr=0.05,
                                     w=None, b=None,
                                     x_col='km', y_col='price',
                                     x_label='kilometers',
                                     y_label='price'):
    """
    Plot the scattered dataset and the linear regression line.
    :param data: the dataset containing 'km' and 'price' columns
    :param lr: the learning rate used for gradient descent (default is 0.05)
    :param w: the slope of the regression line
              (if None, computed via gradient descent)
    :param b: the y-intercept of the regression line
              (if None, computed via gradient descent)
    :param x_col: the column name for the x-axis feature (default is 'km')
    :param y_col: the column name for the y-axis target (default is 'price')
    :param x_label: label for the x-axis (default is 'kilometers')
    :param y_label: label for the y-axis (default is 'price')
    :return: None
    """
    # Validate columns exist
    if x_col not in data.columns:
        raise ValueError(f"Column '{x_col}' not found in DataFrame. \
        Available columns: {list(data.columns)}")
    if y_col not in data.columns:
        raise ValueError(f"Column '{y_col}' not found in DataFrame. \
        Available columns: {list(data.columns)}")

    x_min, x_max = data[x_col].min(), data[x_col].max()
    pad = 0.05 * (x_max - x_min) if x_max > x_min else 1.0
    x_plot = np.linspace(x_min - pad, x_max + pad, 200)
    fig, ax = plt.subplots(figsize=(10, 5))

    # Scatter of the dataset
    ax.plot(data[x_col], data[y_col], 'o', label='Data')
    ax.set_xlabel(x_label)
    ax.set_ylabel(y_label)
    ax.set_title(
        f'Scatter dataset + linear regression function (learning rate: {lr})')

    # Use provided w,b or compute them
    if w is None or b is None:
        w, b = gradient_descent(data, lr)[0:2]
    # Plot of linear regression model
    y_plot = w * x_plot + b

    line, = ax.plot(x_plot, y_plot)
    fig.tight_layout()

    plt.show()


def main():
    """
    Main function To load dataset and run gradient descent.
    Optionally prints algorithm precision and plots results.
    """
    args = get_args()
    x_index = args.x_index
    y_index = args.y_index
    x_label = args.x_label
    y_label = args.y_label
    learning_rate = args.learning_rate
    max_iterations = args.max_iterations
    dataset_file = args.dataset
    if not dataset_file.is_file():
        print(f"Error: Dataset file '{dataset_file}' not found.")
        exit(1)
    try:
        dataset = pd.read_csv(dataset_file)
    except Exception as e:
        print(f"Error: Failed to read dataset file '{dataset_file}': {e}")
        exit(1)

    # Validate CSV structure for standalone use
    required_columns = [x_index, y_index]
    missing_columns = [col for col in required_columns
                       if col not in dataset.columns]
    if missing_columns:
        print(f"Error: CSV file must contain columns: {required_columns}")
        print(f"Missing columns: {missing_columns}")
        print(f"Found columns: {list(dataset.columns)}")
        exit(1)

    data = dataset.dropna().reset_index(drop=True)

    # Validate we have data after dropping NaN
    if data.empty:
        print("Error: No valid data rows found after removing missing values.")
        exit(1)

    # Run gradient descent
    w, b, iterations, history = gradient_descent(
        data,
        learning_rate=learning_rate,
        max_iters=max_iterations,
        x_col=x_index,
        y_col=y_index,
        track_history=True
    )

    print(f"Learned parameters: w = {w}, b = {b} - Iterations: {iterations}",
          end='')
    print(f"{' (converged)' if iterations < max_iterations
             else ' (max iterations reached)'}")

    if args.show_algorithm_precision:
        # Calculate predictions and precision
        x = data[x_index].to_numpy(dtype=float)
        y_true = data[y_index].to_numpy(dtype=float)
        y_pred = w * x + b
        precision = 1 - np.mean(np.abs(y_true - y_pred) / y_true)
        print(f"Algorithm precision on training data: {precision * 100:.6f}%")

    if args.plot:
        # Plot dataset and regression line
        plot_dataset_and_regression_line(data,
                                         lr=learning_rate,
                                         w=w,
                                         b=b,
                                         x_col=x_index,
                                         y_col=y_index,
                                         x_label=x_label,
                                         y_label=y_label)


if __name__ == "__main__":
    main()
