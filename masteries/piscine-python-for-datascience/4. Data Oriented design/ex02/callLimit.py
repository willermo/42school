from typing import Any
from functools import wraps


def callLimit(limit: int):
    """Limits the number of times a function can be called."""

    count = 0

    def callLimiter(function):
        """Inner function to limit calls to the decorated function."""

        @wraps(function)
        def limit_function(*args: Any, **kwds: Any):
            """Function that enforces the call limit."""
            if not isinstance(limit, int):
                print("Error: limit must be an integer, "
                      f"you provided {limit} as {type(limit)}")
                return None
            nonlocal count
            if count < limit:
                count += 1
                return function(*args, **kwds)
            else:
                print(f"Error: {function} call too many times")
                return None
        return limit_function

    return callLimiter


def main():
    """Main function to indicate that this module is not standalone."""
    print("This module is not meant to be used as a standalone script.")


if __name__ == "__main__":
    main()
