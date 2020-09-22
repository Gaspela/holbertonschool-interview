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
    Each integer represents 1 binary of data, therefore you only need to handle
    the 8 least significant bits of each integer
    """
    int_numbytes = 0
    for num in data:
        binary = format(num, '#010b')[-8:]
        if int_numbytes == 0:
            if binary[0] == '1':
                int_numbytes = len(binary.split('0')[0])
            if int_numbytes > 4 or int_numbytes == 1:
                return False
            if int_numbytes == 0:
                continue
        else:
            if not (binary[0] == '1' and binary[1] == '0'):
                return False
        int_numbytes -= 1
    return int_numbytes == 0
