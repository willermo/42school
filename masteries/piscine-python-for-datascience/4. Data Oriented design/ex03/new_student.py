"""Student class"""
from dataclasses import dataclass, field
import random
import string


def generate_id() -> str:
    """Generate a random 15-character ID."""
    return "".join(random.choices(string.ascii_lowercase, k=15))


def generate_login(name: str, surname: str) -> str:
    """Generate a login based on the student's name and surname."""
    return f"{name[0].upper()}{surname.lower()}"


@dataclass
class Student:
    """Class representing a student."""
    name: str
    surname: str
    active: bool = True
    login: str = field(init=False)
    id: str = field(default_factory=generate_id, init=False)

    def __post_init__(self):
        """Post-initialization to set login and validate inputs."""
        # Type and non-empty checks
        if not isinstance(self.name, str) or not isinstance(self.surname, str):
            raise TypeError("name and surname must be instances of str")
        if not self.name.strip() or not self.surname.strip():
            raise ValueError("name and surname must be non-empty strings")
        self.login = generate_login(self.name, self.surname)

    @classmethod
    def create(cls, name, surname, **kwargs):
        """Safe constructor: returns instance or None and prints error."""
        try:
            return cls(name, surname, **kwargs)
        except (TypeError, ValueError) as e:
            print(f"Failed to create Student: {e}")
            return None
