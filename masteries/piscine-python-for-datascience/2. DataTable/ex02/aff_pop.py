from load_csv import load
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter
import numpy as np
import pandas as pd
import sys


def parse_suffixed_number(s: str) -> float:
    """Convert a string with a suffix (K, M, B) to a float.

    Parameters: s (str): The string to convert.

    Returns: float: The converted float.
    """
    if pd.isna(s):
        return np.nan
    s = str(s).strip().upper()
    multipliers = {'K': 1e3, 'M': 1e6, 'B': 1e9}
    if s[-1] in multipliers:
        return float(s[:-1]) * multipliers[s[-1]]
    return float(s)


def aff_pop(country: str) -> None:
    """Displays the population of a country over time.
    Displays the population of Italy over time compared to the population
    of the country provided.

    Parameters: country (str): The country to display the population of.

    Returns: None
    """
    my_campus = "Italy"
    population_total = load("population_total.csv")
    if population_total is None:
        print("Error loading csv file")
        sys.exit(1)
    if getattr(population_total, "empty", False):
        print("Loaded DataFrame is empty")
        sys.exit(1)
    try:
        population = population_total.set_index("country")
        population = population.map(parse_suffixed_number)
        years = population.columns.astype(int)
    except Exception as err:
        print(f"{err.__class__.__name__}: {err}")
        sys.exit(1)
    plt.figure(figsize=(12, 6))
    try:
        plt.plot(years, population.loc[my_campus].astype(float).values)
        plt.plot(years, population.loc[country].astype(float).values)
    except KeyError as err:
        print(f"{err.__class__.__name__}: {err}")
        sys.exit(1)
    plt.xlabel("Year")
    plt.ylabel("Population")
    plt.title("Population Projections")
    plt.legend([my_campus, country])
    ax = plt.gca()  # Get Current Axes
    ax.yaxis.set_major_formatter(FuncFormatter(lambda x, pos: f'{x/1e6:.0f}M'))
    plt.show()


if __name__ == "__main__":
    if len(sys.argv) == 2:
        aff_pop(sys.argv[1])
    else:
        print("Usage: python3 aff_pop.py <campus>")
        sys.exit(1)
