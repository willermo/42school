from load_csv import load
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter
import sys


def projection_life(year: str = "1900") -> None:
    """Projects life expectancy in relation to the gross national product
    of the year 1900 for each country"""
    ley = "life_expectancy_years.csv"
    ipp = "income_per_person_gdppercapita_ppp_inflation_adjusted.csv"
    plt.figure(figsize=(8, 5))
    try:
        plt.scatter(load(ipp)[year], load(ley)[year])
    except (KeyError, TypeError) as err:
        print(f"{err.__class__.__name__}: {err}")
        sys.exit(1)
    plt.xlabel("Gross domestic product")
    plt.ylabel("Life expectancy")
    plt.title(f"{year}")
    ax = plt.gca()  # Get Current Axes
    ax.xaxis.set_major_formatter(FuncFormatter(lambda x, pos: f'{x/1e3:.0f}k'
                                               if x >= 1e3 else f'{x:.0f}'))
    plt.show()


if __name__ == "__main__":
    projection_life()
