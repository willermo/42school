"""
Tests for ft_package.
"""

import pytest
from ft_package import count_in_list


def test_count_in_list_basic():
    """Test basic functionality of count_in_list."""
    assert count_in_list(["toto", "tata", "toto"], "toto") == 2
    assert count_in_list(["toto", "tata", "toto"], "tutu") == 0


def test_count_in_list_empty_list():
    """Test count_in_list with empty list."""
    assert count_in_list([], "anything") == 0


def test_count_in_list_single_item():
    """Test count_in_list with single item list."""
    assert count_in_list(["test"], "test") == 1
    assert count_in_list(["test"], "other") == 0


def test_count_in_list_numbers():
    """Test count_in_list with numbers."""
    assert count_in_list([1, 2, 3, 1, 1], 1) == 3
    assert count_in_list([1, 2, 3, 1, 1], 4) == 0


def test_count_in_list_mixed_types():
    """Test count_in_list with mixed types."""
    assert count_in_list([1, "1", 1, "test"], 1) == 2
    assert count_in_list([1, "1", 1, "test"], "1") == 1


def test_count_in_list_type_error():
    """Test count_in_list raises TypeError for non-list input."""
    with pytest.raises(TypeError):
        count_in_list("not a list", "item")

    with pytest.raises(TypeError):
        count_in_list(123, "item")
