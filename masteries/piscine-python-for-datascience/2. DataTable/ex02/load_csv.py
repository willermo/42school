import sys
import pandas as pd
from pandas import DataFrame


def load(path: str) -> DataFrame:
    """Load a CSV file into a pandas DataFrame, prints its shape and returns it

        Parameters: path (str): The path to the CSV file.

        Returns: DataFrame: The loaded DataFrame.
    """
    try:
        csv_file = pd.read_csv(path)
    except Exception as err:
        print(f"{err.__class__.__name__}: {err}")
        return None
    print(f"Loading dataset of dimensions {csv_file.shape}")
    return csv_file


def main(args):
    """Main function"""
    if len(args) == 1:
        print("Missing argument")
        print("Usage: python3 load_csv.py <filename>")
        sys.exit(1)
    if len(args) > 2:
        print("Too many arguments")
        print("Usage: python3 load_csv.py <filename>")
        sys.exit(1)
    print(load(args[1]))


if __name__ == '__main__':
    main(sys.argv)
