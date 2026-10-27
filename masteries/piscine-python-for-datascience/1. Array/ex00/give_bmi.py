import sys
import numpy as np


def validate_input(
        height: list[int | float],
        weight: list[int | float]) -> tuple[np.ndarray, np.ndarray]:

    # Convert to numpy arrays
    h = np.asarray(height)
    w = np.asarray(weight)

    if h.shape != w.shape:
        raise ValueError("Lists must have the same length")
    if h.size == 0:
        raise ValueError("Lists must have at least one element")

    # Ensure numeric type
    if not np.issubdtype(h.dtype, np.number) or not np.issubdtype(w.dtype,
                                                                  np.number):
        raise TypeError("Arguments must be numeric")

    # Check for positive values
    if np.any(h <= 0) or np.any(w <= 0):
        raise ValueError("Heights and weights must be positive numbers")

    return h, w


def give_bmi(
        height: list[int | float],
        weight: list[int | float]) -> list[int | float]:
    try:
        h, w = validate_input(height, weight)
    except (ValueError, TypeError) as err:
        print(f"{err.__class__.__name__}: {err}")
        sys.exit(1)

    bmi = w / h ** 2
    return bmi.tolist()


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    arr = np.asarray(bmi)
    return (arr > limit).tolist()
