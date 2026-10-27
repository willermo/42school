import sys


def main():
    """Calculates the number of each type of character in a given text.

    Types of characters include uppercase letters, lowercase letters,
    punctuation marks, spaces, and digits.

    The program takes a single argument, the text to be analyzed.
    If no argument is provided, the program prompts the user for the text.
    If the user provides more than one argument, the program exits with an
    error.
    If the input is valid, the program counts the characters and prints
    the results.
    """
    char_types = {
        "upper letters": 0,
        "lower letters": 0,
        "punctuation marks": 0,
        "spaces": 0,
        "digits": 0
    }
    text = ''
    try:
        if len(sys.argv) > 2:
            raise AssertionError("too many arguments")
        elif len(sys.argv) < 2:
            text = input("What is the text to count?")
        else:
            text = sys.argv[1]
        for char in text:
            if char.isupper():
                char_types["upper letters"] += 1
            elif char.islower():
                char_types["lower letters"] += 1
            elif char.isspace():
                char_types["spaces"] += 1
            elif char.isdigit():
                char_types["digits"] += 1
            else:
                char_types["punctuation marks"] += 1
        total = sum(char_types.values())
        print(f"The text contains {total} characters:")
        for key, value in char_types.items():
            print(f"{value} {key}")
    except AssertionError as err:
        print(f"AssertionError: {err}")
        sys.exit(1)


if __name__ == "__main__":
    main()
