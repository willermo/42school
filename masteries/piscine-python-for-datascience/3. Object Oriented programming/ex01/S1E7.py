from S1E9 import Character


class Baratheon(Character):
    """Class representing a Baratheon character, inheriting from Character."""
    family_name = "Baratheon"
    eyes = "brown"
    hairs = "dark"

    def die(self):
        """
        Sets the character's is_alive attribute to False, thus killing it.
        """
        self.is_alive = False

    def __init__(self, first_name, is_alive=True):
        """Constructor for Baratheon class.

        Args:
            first_name (str): Name of the Baratheon character.
            is_alive (bool): Status of the character, default is True.
        Returns:
            A new instance of Baratheon.
        """
        super().__init__(first_name, is_alive, self.family_name)
        self.eyes = self.eyes
        self.hairs = self.hairs


class Lannister(Character):
    """Class representing a Lannister character, inheriting from Character."""
    family_name = "Lannister"
    eyes = "blue"
    hairs = "light"

    def die(self):
        """
        Sets the character's is_alive attribute to False, thus killing it.
        """
        self.is_alive = False

    def __init__(self, first_name, is_alive=True):
        """Constructor for Lannister class.

        Args:
            first_name (str): Name of the Lannister character.
            is_alive (bool): Status of the character, default is True.
        Returns:
            A new instance of Lannister.
        """
        super().__init__(first_name, is_alive, self.family_name)
        self.first_name = first_name
        self.eyes = self.eyes
        self.hairs = self.hairs

    @classmethod
    def create_lannister(cls, first_name, is_alive=True):
        """Factory method to create a Lannister instance.

        Args:
            first_name (str): Name of the Lannister character.
            is_alive (bool): Status of the character, default is True.

        Returns:
            A new instance of Lannister.
        """
        return cls(first_name, is_alive)
    pass
