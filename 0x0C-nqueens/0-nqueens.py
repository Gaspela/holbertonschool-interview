#!/usr/bin/python3
"""
size Queens (Base geeksforgeeks SHUBHAMSINGH10)
"""
import sys


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    size = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)

if size < 4:
    print("N must be at least 4")
    exit(1)

k = 1


def printSolution(board):
    """
    A utility function to print solution
    """
    printsol = []
    global k
    k = k + 1
    for i in range(size):
        for j in range(size):
            if board[i][j] == 1:
                printsol.append([i, j])
    print(printsol)


def isSafe(board, row, col):
    """
    A utility function to check if a queen can
    be placed on board[row][col].
    """
    for i in range(col):
        if board[row][i]:
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j]:
            return False
        i -= 1
        j -= 1
    i = row
    j = col

    while j >= 0 and i < size:
        if board[i][j]:
            return False
        i = i + 1
        j = j - 1
    return True


def solveNQUtil(board, col):
    """
    A recursive utility function to solve N
    Queen problem
    """
    if col == size:
        printSolution(board)
        return True

    res = False
    for i in range(size):
        if isSafe(board, i, col):
            board[i][col] = 1
            res = solveNQUtil(board, col + 1) or res
            board[i][col] = 0
    return res


def solveNQ():
    """
    This function solves the N Queen problem using
    Backtracking
    """
    board = [[0 for j in range(size)] for i in range(size)]
    if solveNQUtil(board, 0) is False:
        pass
        return
    return


solveNQ()
