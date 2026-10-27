#!/usr/bin/env python3
"""
Author: doriani <doriani@student.42roma.it>
Author: gmartin <gmartin@student.42roma.it>
Date: 2025-10-21
Purpose: Custom implementation of pandas describe() method.
Description:
    This module provides a custom implementation of pandas DataFrame.describe()
    method. It generates descriptive statistics that summarize the central
    tendency, dispersion, and shape of a dataset's distribution excluding
    NaN values.
"""
import pandas as pd
import argparse
from pathlib import Path


def get_args():
    """Get command-line arguments"""

    parser = argparse.ArgumentParser(
        description='Custom implementation of pandas describe() method',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)

    parser.add_argument('dataset',
                        metavar='FILE',
                        help='The csv file containing the dataset',
                        type=Path)

    return parser.parse_args()


def numeric_dataframe(df):
    """Return dataframe containing only numeric columns."""
    return df.select_dtypes(include='number')


def count(dataset):
    """Count non-NA cells for each column in the dataset"""
    results = {}
    for column in dataset:
        cnt = 0
        for value in dataset[column]:
            if not pd.isna(value):
                cnt += 1
        results[column] = int(cnt)
    return results


def mean(dataset):
    """Calculate the mean of each column in the dataset"""
    results = {}
    for column in dataset:
        values_sum = 0
        counts = 0
        for value in dataset[column]:
            if pd.notna(value):
                values_sum += value
                counts += 1
        results[column] = values_sum / counts if counts > 0 else float('nan')
    return results


def std(dataset):
    """Calculate the standard deviation of each column in the dataset"""
    results = {}
    variance_val = variance(dataset)
    for column in dataset:
        std_val = variance_val[column] ** 0.5\
            if pd.notna(variance_val[column]) else float('nan')
        results[column] = std_val
    return results


def dataset_min(dataset):
    """Calculate the minimum of each column in the dataset"""
    results = {}
    for column in dataset:
        min_val = None
        for value in dataset[column]:
            if pd.notna(value):
                if min_val is None or value < min_val:
                    min_val = value
        results[column] = min_val
    return results


def twenty_five_percentile(dataset):
    """Calculate the 25th percentile of each column in the dataset"""
    results = {}
    for column in dataset:
        sorted_values = sorted(
            [value for value in dataset[column] if pd.notna(value)]
        )
        n = len(sorted_values)
        if n == 0:
            percentile_25 = float('nan')
        else:
            k = 0.25 * (n - 1)
            f = int(k)
            c = k - f
            if f + 1 < n:
                percentile_25 = sorted_values[f] + c * (sorted_values[f + 1] -
                                                        sorted_values[f])
            else:
                percentile_25 = sorted_values[f]
        results[column] = percentile_25
    return results


def fifty_percentile(dataset):
    """Calculate the 50th percentile (median) of each column in the dataset"""
    results = {}
    for column in dataset:
        sorted_values = sorted(
            [value for value in dataset[column] if pd.notna(value)]
        )
        n = len(sorted_values)
        if n == 0:
            percentile_50 = float('nan')
        else:
            k = 0.50 * (n - 1)
            f = int(k)
            c = k - f
            if f + 1 < n:
                percentile_50 = sorted_values[f] + c * (sorted_values[f + 1] -
                                                        sorted_values[f])
            else:
                percentile_50 = sorted_values[f]
        results[column] = percentile_50
    return results


def seventy_five_percentile(dataset):
    """Calculate the 75th percentile of each column in the dataset"""
    results = {}
    for column in dataset:
        sorted_values = sorted(
            [value for value in dataset[column] if pd.notna(value)]
        )
        n = len(sorted_values)
        if n == 0:
            percentile_75 = float('nan')
        else:
            k = 0.75 * (n - 1)
            f = int(k)
            c = k - f
            if f + 1 < n:
                percentile_75 = sorted_values[f] + c * (sorted_values[f + 1] -
                                                        sorted_values[f])
            else:
                percentile_75 = sorted_values[f]
        results[column] = percentile_75
    return results


def dataset_max(dataset):
    """Calculate the maximum of each column in the dataset"""
    results = {}
    for column in dataset:
        max_val = None
        for value in dataset[column]:
            if pd.notna(value):
                if max_val is None or value > max_val:
                    max_val = value
        results[column] = max_val
    return results


def variance(dataset):
    """Calculate the variance of each column in the dataset"""
    results = {}
    mean_val = mean(dataset)
    for column in dataset:
        sum_squared_diff = 0
        counts = 0
        for value in dataset[column]:
            if pd.notna(value):
                sum_squared_diff += (value - mean_val[column]) ** 2
                counts += 1
        variance_val = (sum_squared_diff /
                        (counts - 1)) if counts > 1 else float('nan')
        results[column] = variance_val
    return results


def skewness(dataset):
    """Calculate the skewness of each column in the dataset"""
    results = {}
    for column in dataset:
        n = 0
        mean_val = 0
        M2 = 0
        M3 = 0
        for value in dataset[column]:
            if pd.notna(value):
                n += 1
                delta = value - mean_val
                mean_val += delta / n
                delta2 = value - mean_val
                M2 += delta * delta2
                M3 += delta * delta2 * delta2

        if n < 3:
            skewness_val = float('nan')
        else:
            variance_val = M2 / (n - 1)
            std_dev = variance_val ** 0.5
            skewness_val = ((n * M3) /
                            ((n - 1) * (n - 2) *
                             (std_dev ** 3))) if std_dev != 0 else float('nan')
        results[column] = skewness_val
    return results


def kurtosis(dataset):
    """Calculate the kurtosis of each column in the dataset"""
    results = {}
    for column in dataset:
        n = 0
        mean_val = 0
        M2 = 0
        M4 = 0
        for value in dataset[column]:
            if pd.notna(value):
                n += 1
                delta = value - mean_val
                mean_val += delta / n
                delta2 = value - mean_val
                M2 += delta * delta2
                M4 += delta * delta2 * delta2 * delta2

        if n < 4:
            kurtosis_val = float('nan')
        else:
            variance_val = M2 / (n - 1)
            std_dev = variance_val ** 0.5
            kurtosis_val = ((n * (n + 1) * M4) /
                            ((n - 1) * (n - 2) * (n - 3) * (std_dev ** 4)) -
                            (3 * (n - 1) ** 2) /
                            ((n - 2) *
                             (n - 3))) if std_dev != 0 else float('nan')
        results[column] = kurtosis_val
    return results


def median(dataset):
    """Calculate the median of each column in the dataset"""
    results = {}
    for column in dataset:
        sorted_values = sorted(
            [value for value in dataset[column] if pd.notna(value)]
        )
        n = len(sorted_values)
        if n == 0:
            median_val = float('nan')
        elif n % 2 == 1:
            median_val = sorted_values[n // 2]
        else:
            median_val = (sorted_values[n // 2 - 1] +
                          sorted_values[n // 2]) / 2
        results[column] = median_val
    return results


def range_stat(dataset):
    """Calculate the range of each column in the dataset"""
    results = {}
    min_vals = dataset_min(dataset)
    max_vals = dataset_max(dataset)
    for column in dataset:
        if pd.notna(min_vals[column]) and pd.notna(max_vals[column]):
            range_val = max_vals[column] - min_vals[column]
        else:
            range_val = float('nan')
        results[column] = range_val
    return results


def interquartile_range(dataset):
    """Calculate the interquartile range of each column in the dataset"""
    results = {}
    q1 = twenty_five_percentile(dataset)
    q3 = seventy_five_percentile(dataset)
    for column in dataset:
        if pd.notna(q1[column]) and pd.notna(q3[column]):
            iqr_val = q3[column] - q1[column]
        else:
            iqr_val = float('nan')
        results[column] = iqr_val
    return results


def mad(dataset):
    """Calculate the mean absolute deviation of each column in the dataset"""
    results = {}
    mean_val = mean(dataset)
    for column in dataset:
        sum_abs_dev = 0
        counts = 0
        for value in dataset[column]:
            if pd.notna(value):
                sum_abs_dev += abs(value - mean_val[column])
                counts += 1
        mad_val = sum_abs_dev / counts if counts > 0 else float('nan')
        results[column] = mad_val
    return results


def describe(dataset):
    """Generate descriptive statistics of the DataFrame for numeric columns"""
    filtered_dataset = numeric_dataframe(dataset)

    stats = {
        'Count': count(filtered_dataset),
        'Mean': mean(filtered_dataset),
        'Std': std(filtered_dataset),
        'Min': dataset_min(filtered_dataset),
        '25%': twenty_five_percentile(filtered_dataset),
        '50%': fifty_percentile(filtered_dataset),
        '75%': seventy_five_percentile(filtered_dataset),
        'Max': dataset_max(filtered_dataset),
        'Variance': variance(filtered_dataset),
        'Skewness': skewness(filtered_dataset),
        'Kurtosis': kurtosis(filtered_dataset),
        'Median': median(filtered_dataset),
        'Range': range_stat(filtered_dataset),
        'IQR': interquartile_range(filtered_dataset),
        'MAD': mad(filtered_dataset),
    }

    # Build DataFrame with stats as index and numeric columns as columns
    return pd.DataFrame(stats).T


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

    desc = describe(dataset)

    pd.set_option('display.float_format', '{:.6f}'.format)
    print(desc)


if __name__ == '__main__':
    main()
