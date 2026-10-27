"""
Author: doriani <doriani@student.42roma.it>
Author: gmartin <gmartin@student.42roma.it>
Date: 2025-10-29
Description:
    Plot utilities for Hogwarts houses datasets.
"""
import math
import random
import matplotlib.pyplot as plt
import pandas as pd
from describe import numeric_dataframe, mean, variance, std


def pearson(df: pd.DataFrame, c1: str, c2: str) -> float:
    """
    Function to calculate Pearson correlation index
    of two columns from a pandas DataFrame

    Arguments:
    - df: the pandas DataFrame representing the dataset
    - c1: the column name of the DataFrame relative to the first column values
    - c2: the column name of the DataFrame relative to the second column values

    Returns: the Pearson correlation index as float
    """

    # define the Series for both courses
    x, y = df[c1], df[c2]

    # create filtered pairs (exclude NaN)
    pairs = [(a, b) for a, b in zip(x, y)
             if (pd.notna(a) and pd.notna(b)
                 and math.isfinite(float(a)) and math.isfinite(float(b)))]

    # ensure we have at least 2 pairs for sample statistics
    if len(pairs) < 2:
        return math.nan

    # create one-column DataFrames containing values of the courses
    x_df = pd.DataFrame({"x": [a for a, _ in pairs]})
    y_df = pd.DataFrame({"y": [b for _, b in pairs]})

    # calculate means
    mx = mean(x_df)["x"]
    my = mean(y_df)["y"]

    # sample variances
    vx = variance(x_df)["x"]
    vy = variance(y_df)["y"]

    # guard for types and positive variances (scalars)
    if not (isinstance(vx, (int, float)) and isinstance(vy, (int, float))):
        return math.nan
    if vx <= 0 or vy <= 0:
        return math.nan

    # sample standard deviations
    sx = std(x_df)["x"]
    sy = std(y_df)["y"]

    # sample covariance
    cov = sum((x - mx) * (y - my) for x, y in pairs) / (len(pairs) - 1)

    # return Pearson index
    return cov / (sx * sy)


def pair_combinations(elements: list) -> list:
    """Generate all unique pairs from a list of elements."""
    pairs = []
    n = len(elements)
    for i in range(n):
        for j in range(i+1, n):
            pairs.append((elements[i], elements[j]))
    return pairs


def get_palette(houses, palette: list = None):
    """Get a color palette for the given houses."""

    if palette is None:
        palette = []
    if len(palette) < len(houses):
        additional_colors = plt.get_cmap('tab10').colors
        for i in range(len(houses) - len(palette)):
            palette.append(additional_colors[i % len(additional_colors)])
    palette = {h: palette[i] for i, h in enumerate(houses)}
    return palette


def get_courses(df, non_course: set = None):
    """Get numeric course columns from the dataframe."""
    if non_course is None:
        non_course = {"Index", "Hogwarts House", "First Name",
                      "Last Name", "Birthday", "Best Hand"}
    course_columns = [col for col in df.columns if col not in non_course]
    num_df = numeric_dataframe(df[course_columns])
    return num_df.columns.tolist()


def get_houses(df, house_column: str = None,
               house_order: list = None):
    """Get the list of houses present in the dataframe."""
    if house_column is None:
        house_column = "Hogwarts House"
    if house_order is None:
        house_order = ["Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"]

    houses_present = df[house_column].dropna().unique()
    houses = [h for h in house_order if h in houses_present]
    return houses


def get_pairs(df: pd.DataFrame, courses: list, sort_pairs=True) -> list:
    """Get all unique pairs of courses."""
    pairs = []
    for a, b in pair_combinations(courses):
        r = pearson(df, a, b)
        if pd.notna(r):
            pairs.append((a, b, r))
    if not pairs:
        raise ValueError("No valid course pairs with "
                         "Pearson correlation were found.")
    if sort_pairs:
        pairs.sort(key=lambda x: abs(x[2]), reverse=True)
    return pairs


def get_selected_pairs(pairs, top=2, mid=2, bottom=2, rand=2, seed=42):
    """Get selected pair indices for plotting."""
    def select_indices(num_pairs):
        top_idxs = [i for i in range(min(top, num_pairs))]

        mid_start = max(top, num_pairs // 2 - mid // 2)
        mid_end = min(num_pairs - bottom, mid_start + mid)
        mid_idxs = [i for i in range(mid_start, mid_end)]

        bottom_idxs = [i for i in range(max(0, num_pairs - bottom), num_pairs)]

        used = set(top_idxs + mid_idxs + bottom_idxs)
        candidates = [i for i in range(num_pairs) if i not in used]
        random.seed(seed)
        rand_idxs = random.sample(candidates, k=min(rand, len(candidates)))

        selected_idxs = top_idxs + mid_idxs + bottom_idxs + rand_idxs
        return selected_idxs

    selected_pairs = [pairs[i] for i in select_indices(len(pairs))]
    return selected_pairs
