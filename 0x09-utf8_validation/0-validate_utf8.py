#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """
    Prototype: def validUTF8(data)
    Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 butes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you only need to handle
    the 8 least significant bits of each integer
    """
    int_numbytes = 0
    for num in data:
        if int_numbytes == 0:
            if (num >> 5) == 0b110:
                int_numbytes = 1
            elif (num >> 4) == 0b1110:
                int_numbytes = 2
            elif (num >> 3) == 0b11110:
                int_numbytes = 3
            elif (num >> 7):
                return False
        else:
            if (num >> 6) != 0b10:
                return False
            int_numbytes -= 1
    return int_numbytes == 0
