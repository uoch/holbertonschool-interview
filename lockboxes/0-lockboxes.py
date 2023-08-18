#!/usr/bin/python3
"""Returns True if all boxes are unlocked"""


def canUnlockAll(boxes):
    """Returns True if all boxes are unlocked"""
    x = set([0])

    for index, box in enumerate(boxes):
        for key in box:
            if key != index:
                x.add(key)
    xx = list((sorted(x)))
    for i in range(len(xx)-1):
        if xx[i+1] != int(xx[i])+1:
            return False
    return len(x) >= len(boxes)
