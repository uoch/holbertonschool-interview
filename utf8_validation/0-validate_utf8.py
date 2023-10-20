#!/usr/bin/python3
"""validUTF8 module"""


def validUTF8(data):
    """Determines if a given data set represents a valid UTF-8 encoding"""
    byte_count = 0

    for num in data:
        binary_num = bin(num)[2:]
        binary_num = binary_num.zfill(8)

        if byte_count == 0:
            if binary_num[0] == '0':
                byte_count = 0
            elif binary_num[0] == '110':
                byte_count = 1
            elif binary_num[0:3] == '1110':
                byte_count = 2
            elif binary_num[0:4] == '11110':
                byte_count = 3
            else:
                return False
        else:
            # Check that the byte starts with '10' as a continuation byte
            if binary_num[0:2] != '10':
                return False
            byte_count -= 1

    return byte_count == 0
