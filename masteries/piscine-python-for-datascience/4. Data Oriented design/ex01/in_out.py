import math
import numbers


def square(x: int | float) -> int | float:
    """Returns the square of a number."""
    return x ** 2


def pow(x: int | float) -> int | float:
    """Returns the number raised to the power of itself."""
    if x < 0 and x % 1 != 0:
        raise ValueError("x must be non-negative for pow function "
                         "if x has decimals")
    return x**x


def outer(x: int | float, function) -> object:
    """
    Returns a function that applies 'function' to 'x' each time it is called.
    """

    # validation
    try:
        if not isinstance(x, numbers.Real):
            raise TypeError("x must be a real number")
        if not math.isfinite(x):
            raise ValueError("x must be finite")
        if not callable(function):
            raise TypeError("function must be callable")
    except Exception as exc:
        print("Warning: invalid input parameters:", exc)
        return lambda: "Unable to perform the requested operation"
    else:
        try:
            function(x)
        except Exception as exc:
            print("Warning: function raised during initial test call:", exc)
            return lambda: "Unable to perform the requested operation"

    current = x

    def inner() -> float:
        """Applies the given function to the current value and updates it."""

        nonlocal current
        try:
            current = function(current)
        except Exception as exc:
            raise RuntimeError("function raised during inner call") from exc
        if not isinstance(current, numbers.Real) or not math.isfinite(current):
            raise ValueError("function returned a non-finite/non-real value")
        return current

    return inner


def main():
    """Main function to indicate that this module is not standalone."""
    print("This module is not meant to be used as a standalone script.")


if __name__ == "__main__":
    main()
