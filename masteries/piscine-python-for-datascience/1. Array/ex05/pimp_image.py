import numpy as np

from numpy import ndarray as array
import matplotlib.pyplot as plt


def display_image(image, title, mode=None):
    """Displays the image"""
    plt.title(title)
    plt.axis('off')
    plt.imshow(image, cmap='gray' if mode == "grayscale" else None)
    try:
        plt.show()
    except Exception as err:
        print(err)
        out_path = "inverted.jpeg"
        plt.savefig(out_path, bbox_inches='tight')
        print(f"Saved inverted image to {out_path}")


def ft_invert(array) -> array:
    """Inverts the color of the image received."""
    inverted = 255 - array
    display_image(inverted, "Inverted image")


def ft_red(array) -> array:
    """Extracts the red channel of the image received."""
    # Isolate the red channel and zero out green and blue
    # Create a 3-channel image where only the red channel is kept
    red_channel = array[:, :, 0:1]  # keep red channel with shape (H, W, 1)
    zeros = red_channel * 0           # (H, W, 1) filled with zeros
    red_image = np.concatenate([red_channel, zeros, zeros], axis=2)  # (H, W,3)
    display_image(red_image, "Red image")


def ft_green(array) -> array:
    """Extracts the green channel of the image received."""
    green_channel = array[:, :, 1:2]  # keep red channel with shape (H, W, 1)
    zeros = green_channel - green_channel  # (H, W, 1) filled with zeros
    green_image = np.concatenate([zeros, green_channel, zeros], axis=2)
    display_image(green_image, "Green image")


def ft_blue(array) -> array:
    """Extracts the blue channel of the image received."""
    blue_channel = array[:, :, 2:3]  # blue channel with shape (H, W, 1)
    zeros_bool = (blue_channel == blue_channel)  # all True booleans
    zeros = zeros_bool.astype(blue_channel.dtype)  # cast to image dtype
    blue_image = np.concatenate([zeros, zeros, blue_channel], axis=2)
    display_image(blue_image, "Blue image")


def ft_grey(array) -> array:
    """
    Converts the image to grayscale by duplicating a single color channel.
    """
    grey_image = array[:, :, 0:1] / 3 + array[:, :, 1:2] / 3 \
        + array[:, :, 2:3] / 3
    display_image(grey_image, "Grey image", "grayscale")


if __name__ == "__main__":
    pass
