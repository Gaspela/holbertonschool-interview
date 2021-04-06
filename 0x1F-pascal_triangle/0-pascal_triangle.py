#!/usr/bin/python3
"""
Pascal's Triangle
"""


def pascal_triangle(n):
    """
    Returns an empty list if n <= 0
    You can assume n will be always an integer
    """
    matrix = []

    if n <= 0:
        return matrix

    for i in range(1, (n + 1)):
        row = []
        for j in range(i):
            row.append(1)
        matrix.append(row)
    for i in range(len(matrix)):
        for j in range(i):
            if j != 0:
                matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1]

    return (matrix)
