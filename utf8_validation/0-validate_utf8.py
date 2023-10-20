#!/usr/bin/python3
"""utf-8 validation"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    remaining_bytes = 0

    for num in data:
        if remaining_bytes == 0:
            if (num & 0b10000000) == 0:
                remaining_bytes = 0
            elif (num & 0b11100000) == 0b11000000:
                remaining_bytes = 1
            elif (num & 0b11110000) == 0b11100000:
                remaining_bytes = 2
            elif (num & 0b11111000) == 0b11110000:
                remaining_bytes = 3
            else:
                return False
        else:
            if (num & 0b11000000) != 0b10000000:
                return False
            remaining_bytes -= 1

    return remaining_bytes == 0
