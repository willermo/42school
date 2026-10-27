import numpy as np

from load_image import ft_load
import matplotlib.pyplot as plt


def transpose(matrix):
    """Transposes the matrix passed as argument"""
    transposed = np.array([[matrix[j][i] for j in range(len(matrix))]
                           for i in range(len(matrix[0]))])
    return transposed


def rotate(image_path="animal.jpeg", start_h=100, start_w=450,
           len_h=400, len_w=400, mode="grayscale"):
    """Rotates the image"""
    image = ft_load("animal.jpeg")
    zoomed_image = image[start_h:start_h+len_h, start_w:start_w+len_w, 0
                         if mode == "grayscale" else 3]
    print(f"The shape of image is: {zoomed_image.shape}\n{zoomed_image}")
    transposed_zoomed_image = transpose(zoomed_image)
    print(f"New shape after Transpose: {transposed_zoomed_image.shape}")
    print(f"{transposed_zoomed_image}")
    plt.imshow(transposed_zoomed_image, cmap='gray'
               if mode == "grayscale" else None)
    try:
        plt.show()
    except Exception as err:
        print(err)
        out_path = "zoomed.jpeg"
        plt.savefig(out_path, bbox_inches='tight')
        print(f"Saved zoomed image to {out_path}")


if __name__ == "__main__":
    rotate()
