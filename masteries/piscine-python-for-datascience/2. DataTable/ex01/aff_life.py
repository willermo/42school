from load_csv import load
import matplotlib.pyplot as plt
import sys


def aff_life(country: str = "Italy") -> None:
    """Displays the life expectancy of a country over time.
    Defaults to Italy if no country is provided.

    Parameters: country (str): The country to display the life expectancy of.

    Returns: None
    """
    life_expectancy = load("life_expectancy_years.csv")
    if life_expectancy is None:
        print("Error loading csv file")
        sys.exit(1)
    if getattr(life_expectancy, "empty", False):
        print("Loaded DataFrame is empty")
        sys.exit(1)
    try:
        life = life_expectancy.set_index("country")
        years = life.columns.astype(int)
    except Exception as err:
        print(f"{err.__class__.__name__}: {err}")
        sys.exit(1)

    plt.figure(figsize=(12, 6))
    try:
        plt.plot(years, life.loc[country].astype(float).values)
    except KeyError as err:
        print(f"{err.__class__.__name__}: {err}")
        sys.exit(1)
    plt.xlabel("Year")
    plt.ylabel("Life expectancy")
    plt.title(f"{country} Life expectancy Projections")
    plt.show()


if __name__ == "__main__":
    aff_life()
