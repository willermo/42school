import math
from typing import Any


def is_int_or_float(arg: Any) -> bool:
    if isinstance(arg, (bool, str)):
        return False
    try:
        val = float(arg)
    except (TypeError, ValueError):
        return False
    return math.isfinite(val)


def ft_mean(*args) -> float:
    return sum(args)/len(args)


def ft_median(*args) -> float:
    """Returns the (lower) median."""
    return sorted(args)[len(args)//2]


def ft_quartile(*args) -> list[float]:
    """Returns the first and third quartiles."""
    return [float(sorted(args)[len(args)//4]),
            float(sorted(args)[3*len(args)//4])]


def ft_variance(*args) -> float:
    """Returns the population variance."""
    mean = ft_mean(*args)
    return sum((x - mean) ** 2 for x in args) / len(args)


def ft_std(*args) -> float:
    """Returns the population standard deviation."""
    return ft_variance(*args) ** 0.5


def ft_statistics(*args: Any, **kwargs: Any) -> None:
    """Prints various statistics based on the keyword arguments."""
    args = [arg for arg in args if is_int_or_float(arg)]
    for value in kwargs.values():
        if len(args) == 0:
            print("ERROR")
        elif value == "mean":
            print(f"Mean: {ft_mean(*args)}")
        elif value == "median":
            print(f"Median: {ft_median(*args)}")
        elif value == "quartile":
            print(f"Quartile: {ft_quartile(*args)}")
        elif value == "var":
            print(f"var: {ft_variance(*args)}")
        elif value == "std":
            print(f"std: {ft_std(*args)}")


def main():
    """Main function to indicate that this module is not standalone."""
    print("This module is not meant to be used as a standalone script.")


if __name__ == "__main__":
    main()
