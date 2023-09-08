#!/usr/bin/python3
"""minimum operations"""


def minOperations(n):
    """minimum operations"""
    text = "H"
    h = "H"
    if n <= 1:
        return 0
    i = 1
    while len(text) < (n):
        if len(text) % 2 == 0:
            text += text
            i += 1
        text += h
        i += 1
    print(f"{text} with len =  {len(text)}\n")
    return i
