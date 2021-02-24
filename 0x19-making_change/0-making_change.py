#!/usr/bin/python3
"""
Change comes from within
"""


def makeChange(coins, total):
    """
    Return: fewest number of coins needed to meet total
    If total is 0 or less, return 0
    If total cannot be met by any number of coins you have, return -1
    coins is a list of the values of the coins in your possession
    The value of a coin will always be an integer greater than 0
    """
    coins.sort(reverse=True)
    count = 0

    if total <= 0:
        return 0

    if coins is None or coins == []:
        return -1

    for i in coins:
        count += total // i
        total = total % i
    if total:
        return -1

    return (count)
