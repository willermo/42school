from load_image import ft_load
import matplotlib.pyplot as plt


def zoom(image_path="animal.jpeg", start_h=100, start_w=450,
         len_h=400, len_w=400, mode="grayscale"):
    """Zooms an image and prints its shape and pixel array"""
    image = ft_load("animal.jpeg")
    print(f"The shape of image is: {image.shape}\n{image}")
    zoomed_image = image[start_h:start_h+len_h, start_w:start_w+len_w, 0
                         if mode == "grayscale" else 3]
    print(f"New shape after slicing: {zoomed_image.shape}")
    print(f"{zoomed_image}")
    plt.imshow(zoomed_image, cmap='gray' if mode == "grayscale" else None)
    try:
        plt.show()
    except Exception as err:
        print(err)
        out_path = "zoomed.jpeg"
        plt.savefig(out_path, bbox_inches='tight')
        print(f"Saved zoomed image to {out_path}")


if __name__ == "__main__":
    zoom()
