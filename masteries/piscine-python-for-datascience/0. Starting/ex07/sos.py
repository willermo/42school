import sys

NESTED_MORSE = {
  " ": "/ ",
  "0": "----- ",
  "1": ".---- ",
  "2": "..--- ",
  "3": "...-- ",
  "4": "....- ",
  "5": "..... ",
  "6": "-.... ",
  "7": "--... ",
  "8": "---.. ",
  "9": "----. ",
  "a": ".- ",
  "b": "-... ",
  "c": "-.-. ",
  "d": "-.. ",
  "e": ". ",
  "f": "..-. ",
  "g": "--. ",
  "h": ".... ",
  "i": ".. ",
  "j": ".--- ",
  "k": "-.- ",
  "l": ".-.. ",
  "m": "-- ",
  "n": "-. ",
  "o": "--- ",
  "p": ".--. ",
  "q": "--.- ",
  "r": ".-. ",
  "s": "... ",
  "t": "- ",
  "u": "..- ",
  "v": "...- ",
  "w": ".-- ",
  "x": "-..- ",
  "y": "-.-- ",
  "z": "--.. ",
  ".": ".-.-.- ",
  ",": "--..-- ",
  "?": "..--.. ",
  "!": "-.-.-- ",
  "-": "-....- ",
  "/": "-..-. ",
  "@": ".--.-. ",
  "(": "-.--. ",
  ")": "-.--.- "
}


def sos(text):
    """
    Converts an ascii printable string in morse code.
    Raises AssertionError if input string is invalid
    """
    morse_text = ""
    for char in text:
        if char not in NESTED_MORSE:
            raise AssertionError("the arguments are bad")
        morse_text += NESTED_MORSE[char]
    print(morse_text.strip())


if __name__ == "__main__":
    try:
        if not len(sys.argv) == 2:
            raise AssertionError("the arguments are bad")
        sos(sys.argv[1].lower())
    except AssertionError as err:
        print(f"AssertionError: {err}")
        sys.exit(1)
