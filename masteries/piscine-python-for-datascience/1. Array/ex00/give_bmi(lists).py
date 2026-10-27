import sys


def validate_input(
        height: list[int | float],
        weight: list[int | float]) -> None:
    """Validates the input"""
    if not isinstance(height, list) or not isinstance(weight, list):
        raise TypeError("Arguments must be lists")
    if len(height) != len(weight) or len(height) == 0:
        raise ValueError("Lists must have the same length")
    for h in height:
        if not isinstance(h, (int, float)) or h <= 0:
            raise ValueError("Heights must be positive numbers")
    for w in weight:
        if not isinstance(w, (int, float)) or w <= 0:
            raise ValueError("Weights must be positive numbers")


def give_bmi(
        height: list[int | float],
        weight: list[int | float]) -> list[int | float]:
    """ Returns the body mass index for the given values"""
    try:
        validate_input(height, weight)
    except ValueError as err:
        print(f"ValueError: {err}")
        sys.exit(1)
    except TypeError as err:
        print(f"TypeError: {err}")
        sys.exit(1)
    return [weight / height ** 2 for weight, height in zip(weight, height)]


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """Applies a bmi numeric threshold to the input bmis"""
    return [b > limit for b in bmi]
