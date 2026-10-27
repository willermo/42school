#!/usr/bin/env python3
"""
Author: doriani <doriani@student.42roma.it>
Date: 2025-10-21
Purpose: Predict the price of a used car based on its mileage.
"""


from Trainer import gradient_descent
import argparse
from pathlib import Path
import pandas as pd


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

    return parser.parse_args()


def main():
    """Main function to execute the car price prediction."""

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
    try:
        w, b = gradient_descent(dataset)[:2]
    except ValueError as e:
        print(f"Error during model training: {e}")
        exit(1)
    try:
        mileage = float(input("Enter the mileage of the car (in km): "))
    except ValueError:
        print("Invalid input. Please enter a numeric value for mileage.")
        exit(1)
    else:
        if mileage <= 0:
            print("Mileage must be positive.")
            exit(1)
        price = w * mileage + b
        if price < 0:
            price = 0
        print(f"Predicted price for a car with {mileage} km is: €{int(price)}")
        if price < 1000:
            print("This car is probably a junker.")
            if price == 0:
                print("... or maybe not even that. "
                      f"Who would ever buy a {int(mileage):,} km car?")

if __name__ == "__main__":
    main()