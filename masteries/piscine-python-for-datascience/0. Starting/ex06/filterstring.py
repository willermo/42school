from ft_filter import ft_filter
import sys


def filterstring(word, threshold):
    """filter function to be passed to ft_filter"""
    return True if len(word) > threshold else False


def main(text, threshold):
    """ filters words in given text whose length is bigger than threshold"""
    words = [word for word in text.split()]
    print(list(ft_filter(lambda word: filterstring(word, threshold), words)))


if __name__ == "__main__":
    try:
        if len(sys.argv) != 3:
            raise AssertionError("the arguments are bad")
    except AssertionError as err:
        print(f"AssertionError: {err}")
        sys.exit(1)
    try:
        main(sys.argv[1], int(sys.argv[2]))
    except ValueError as err:
        print(f"ValueError: {err}")
        sys.exit(1)
