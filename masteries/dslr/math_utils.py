"""
Author: doriani <doriani@student.42roma.it>
Author: gmartin <gmartin@student.42roma.it>
Date: 2025-10-29
Description:
    Core mathematical functions for logistic regression.
    Uses numpy for vectorized linear algebra operations.
"""
import numpy as np


def sigmoid(z):
    """
    Compute the sigmoid (logistic) function.

    σ(z) = 1 / (1 + e^(-z))

    Numerically stable: clips z to [-500, 500] to prevent overflow in exp().

    Arguments:
        z: numpy array or scalar

    Returns:
        numpy array or scalar with values in (0, 1)
    """
    z = np.clip(z, -500, 500)
    return 1.0 / (1.0 + np.exp(-z))


def cost_function(h, y, m):
    """
    Compute the binary cross-entropy cost (log-loss).

    J(θ) = -(1/m) Σ[ y·log(h) + (1-y)·log(1-h) ]

    Arguments:
        h: numpy array of shape (m,) — predicted probabilities
        y: numpy array of shape (m,) — true binary labels (0 or 1)
        m: int — number of samples

    Returns:
        float — the cost value
    """
    eps = 1e-15  # small epsilon to avoid log(0)
    h = np.clip(h, eps, 1 - eps)
    return -(1.0 / m) * np.sum(y * np.log(h) + (1 - y) * np.log(1 - h))


def compute_gradient(X, h, y, m):
    """
    Compute the gradient of the cost function with respect to θ.

    ∂J/∂θ_j = (1/m) Σ (h_θ(x_i) - y_i) · x_ij

    Arguments:
        X: numpy array of shape (m, n+1) — feature matrix (with bias column)
        h: numpy array of shape (m,)     — predicted probabilities
        y: numpy array of shape (m,)     — true binary labels
        m: int                           — number of samples

    Returns:
        numpy array of shape (n+1,) — gradient vector
    """
    return (1.0 / m) * X.T.dot(h - y)
