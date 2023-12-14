#!/usr/bin/python3
"""rain """


def trapped_water(walls, i):
    """trapped_water is a to de"""
    left_max = max(walls[:i])
    right_max = max(walls[i + 1:])
    return max(0, min(left_max, right_max) - walls[i])


def rain(walls):
    """determines how much water will be retained after it rains"""
    r = sum(map(lambda i: trapped_water(walls, i), range(1, len(walls) - 1)))
    return r
