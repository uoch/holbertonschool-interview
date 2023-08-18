#!/usr/bin/python3
"""Returns True if all boxes are unlocked"""


def canUnlockAll(boxes):
    """Returns True if all boxes are unlocked"""
    x = set([0])  # Start with the first box unlocked

    for index, box in enumerate(boxes):
        for key in box:
            if key != index:
                x.add(key)
    return len(x) == len(boxes) or ((len(x)-1) == len(boxes))
