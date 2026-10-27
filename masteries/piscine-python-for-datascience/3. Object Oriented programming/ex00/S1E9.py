from abc import ABC, abstractmethod
"""
    Character is an abstract class.
    Stark is a subclass of Character.
"""


class Character(ABC):
    """abstract class for Characters

    Attributes:
        is_alive (bool): True if the character is alive, False otherwise.

    Methods:
        get_is_alive(): Returns if a player is alive or not.
        die(): Abstract method to be implemented in subclasses.
    """
    is_alive = True

    @abstractmethod
    def die(self):
        """
        Subclasses must implement this method to represent the character dying.
        """
        pass

    def __repr__(self):
        """Custom __repr__ method"""
        family_name_str = getattr(self, 'family_name', self.__class__.__name__)
        eyes_str = getattr(self, 'eyes', '')
        hairs_str = getattr(self, 'hairs', '')
        return f"Vector: ('{family_name_str}', '{eyes_str}', '{hairs_str}')"

    def __str__(self):
        """Custom __str__ method"""
        family_name_str = getattr(self, 'family_name', self.__class__.__name__)
        eyes_str = getattr(self, 'eyes', '')
        hairs_str = getattr(self, 'hairs', '')
        return f"Vector: ('{family_name_str}', '{eyes_str}', '{hairs_str}')"

    def __init__(self, first_name, is_alive=is_alive):
        """Constructor for Character class.

        Args:
            family_name (str): Name of the character family.
            is_alive (bool): Status of the character, default is True.

        Returns:
            A new instance of Character.
        """
        self.first_name = first_name
        self.is_alive = is_alive


class Stark(Character):
    """Class representing a Stark character, inheriting from Character."""

    family_name = "Stark"

    def die(self):
        """
        Sets the character's is_alive attribute to False, thus killing it.
        """
        self.is_alive = False

    def __init__(self, first_name, is_alive=True):
        """Constructor for Stark class.

        Args:
            first_name (str): Name of the Stark character.
            is_alive (bool): Status of the character, default is True.
        Returns:
            A new instance of Stark.
        """
        super().__init__(first_name, is_alive)
