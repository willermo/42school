"""
ft_package - A simple Python package for counting items in lists.

This package provides utilities for list operations.
"""
__name__ = "ft_package"
__version__ = "0.0.1"
__summary__ = "A simple Python package for counting items in lists"
__homepage__ = "https://github.com/doriani/ft_package"
__author__ = "doriani"
__email__ = "doriani@student.42roma.it"


from .utils import count_in_list

__all__ = ["count_in_list"]
