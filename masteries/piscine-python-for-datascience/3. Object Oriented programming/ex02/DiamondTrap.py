from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):
    """Class representing a King, inheriting from Baratheon and Lannister."""

    def set_eyes(self, color):
        """Sets the color of the eyes"""
        self.eyes = color

    def set_hairs(self, color):
        """Sets the color of the hairs"""
        self.hairs = color

    def get_eyes(self):
        """Gets the color of the eyes"""
        return self.eyes

    def get_hairs(self):
        """Gets the color of the hairs"""
        return self.hairs

    def __init__(self, first_name, is_alive=True):
        """Constructor for King class.

        Args:
            first_name (str): Name of the King character.
            is_alive (bool): Status of the character, default is True.
        Returns:
            A new instance of King.
        """
        super().__init__(first_name, is_alive)
        self.family_name = Baratheon.family_name
        self.eyes = Baratheon.eyes
        self.hairs = Baratheon.hairs
