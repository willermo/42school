import sys


if len(sys.argv) == 1:
    sys.exit(0)
try:
    if len(sys.argv) != 2:
        raise AssertionError("more than one argument is provided")
    try:
        int(sys.argv[1])
    except ValueError:
        raise AssertionError("argument is not an integer")
except AssertionError as err:
    print(f"AssertionError: {err}")
    sys.exit(1)
print("I'm Even.") if int(sys.argv[1]) % 2 == 0 else print("I'm Odd.")
