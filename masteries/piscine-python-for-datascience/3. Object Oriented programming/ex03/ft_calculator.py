class calculator:
    """
    Represents a calculator to do the the following calculations
    between a vector and a scalar:
        - addition
        - multiplication
        - subtraction
        - division
    """

    def __add__(self, operand: float) -> None:
        """Computes additions (vector + scalar)"""

        self.values = [(x + int(operand)) for x in self.values]
        print(self.values)

    def __radd__(self, operand: float) -> 'calculator':
        """Computes reversed additions (scalar + vector)"""

        # supports 5 + v 1 etc.
        return self.__add__(operand)

    def __mul__(self, operand: float) -> None:
        """Computes multiplications (vector + scalar)"""
        self.values = [(x * int(operand)) for x in self.values]
        print(self.values)

    def __rmul__(self, operand: float) -> 'calculator':
        """Computes reversed multiplications (scalar + vector)"""
        return self.__mul__(operand)

    def __sub__(self, operand: float) -> None:
        """Computes subtractions (vector + scalar)"""
        self.values = [(x - int(operand)) for x in self.values]
        print(self.values)

    def __truediv__(self, operand: float) -> None:
        """Computes divisions (vector + scalar)"""
        try:
            self.values = [(x / int(operand)) for x in self.values]
        except ZeroDivisionError:
            print("Division by zero is not allowed")
        else:
            print(self.values)

    def __init__(self, values):
        """Creates a calculator instance"""
        self.values = values
