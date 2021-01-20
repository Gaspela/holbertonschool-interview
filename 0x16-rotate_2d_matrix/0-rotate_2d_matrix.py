#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees clockwise
    """
    size = len(matrix) - 1
    for i in range(len(matrix) // 2):
        for j in range(i, len(matrix) - 1 - i):
            temp = matrix[i][j]
            matrix[i][j] = matrix[size - j][i]
            matrix[size - j][i] = matrix[size - i][size - j]
            matrix[size - i][size - j] = matrix[j][size - i]
            matrix[j][size - i] = temp
