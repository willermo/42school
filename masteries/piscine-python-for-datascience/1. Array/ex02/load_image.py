import sys
import os

import imageio.v3 as iio
import numpy as np


def validate_input(path: str) -> str:
    """Validates input"""
    if not isinstance(path, str):
        raise TypeError("Input must be a string")

    if not os.path.exists(path):
        raise FileNotFoundError(f"File not found: {path}")

    if not os.path.isfile(path):
        raise ValueError(f"Path is not a file: {path}")

    # Try to get image properties to validate it's a readable image
    try:
        iio.improps(path)
        # If we can read properties, it's a valid image
    except Exception:
        raise ValueError("Unsupported or non-image file")

    return path


def ft_load(path: str) -> np.ndarray:
    """
    Loads an image file, verifies it and prints its shape
    Returns the image pixel content as a numpy array
    """
    try:
        image = iio.imread(validate_input(path))
    except (ValueError, TypeError) as err:
        print(f"{err.__class__.__name__}: {err}")
        sys.exit(1)
    print(f"The shape of image is: {image.shape}")
    return image
