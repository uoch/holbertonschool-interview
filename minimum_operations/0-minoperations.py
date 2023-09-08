#!/usr/bin/python3
"""minimum operations"""


def minOperations(n):
    """minimum operations
    you should track text with paste
    not add 1 every time which means H
    """
    text = 1
    paste = 0
    result = n
    if n <= 1:
        return 0
    count = 0
    while text < n:
        if n % text == 0:
            paste = text
            text += paste
            count += 2
        text += paste
        count += 1
        if text == result:
            break
    return count
