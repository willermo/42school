"""
Utility functions for ft_package.
"""


def count_in_list(lst, item):
    """
    Count occurrences of an item in a list.

    Args:
        lst (list): The list to search in
        item: The item to count

    Returns:
        int: Number of occurrences of item in lst

    Examples:
        >>> count_in_list(["toto", "tata", "toto"], "toto")
        2
        >>> count_in_list(["toto", "tata", "toto"], "tutu")
        0
    """
    if not isinstance(lst, list):
        raise TypeError("First argument must be a list")

    return lst.count(item)
