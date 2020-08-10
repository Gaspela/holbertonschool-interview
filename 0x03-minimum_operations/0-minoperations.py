#!/usr/bin/python3
"""
calculates the fewest number of operations needed to result
in exactly n H characters.
"""


def minOperations(n):
    """
    Minimum Operations
    """
    if n <= 1:
        return 0

    factor = []
    i = 2
    while i <= n:
        if n % i == 0:
            factor.append(i)
            n = n / i
        else:
            i += 1

    return sum(factor)
