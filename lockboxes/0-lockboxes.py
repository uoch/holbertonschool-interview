#!/usr/bin/python3
"""Returns True if all boxes are unlocked"""


def canUnlockAll(boxes):
    """Returns True if all boxes are unlocked"""
    x = set([0])  # Start with the first box unlocked

    for index, box in enumerate(boxes):
        for key in box:
            if key != index:
                x.add(key)
    xx = list((sorted(x)))
    for i in range(len(xx)-1):
        if xx[i+1] != int(xx[i])+1:
            return False
    print(xx)
    print(len(xx))
    print(len(boxes))
    return len(x) >= len(boxes) 
