import sys
import numpy as np


def validate_input(family: list) -> np.ndarray:
    """validates input"""
    if not isinstance(family, list):
        raise TypeError("Input must be a list")

    np_family = np.asarray(family)
    if np_family.ndim != 2:
        raise ValueError("Input must be a 2D array")
    if not np.issubdtype(np_family.dtype, np.number):
        raise TypeError("Input must be numeric")
    if np.any(np_family < 0):
        raise ValueError("Input must be positive numbers")
    return np_family


def slice_me(family: list, start: int, end: int) -> list:
    """slices the array"""
    try:
        np_family = validate_input(family)
    except (ValueError, TypeError) as err:
        print(f"{err.__class__.__name__}: {err}")
        sys.exit(1)
    print(f"My shape is: {np_family.shape}")
    np_family = np_family[start:end]
    print(f"My new shape is: {np_family.shape}")
    return np_family.tolist()
