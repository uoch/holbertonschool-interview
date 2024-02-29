#!/usr/bin/python3
"""find the minimum numb of coins required to make change for a given total"""


def makeChange(coins, total):
    """first sort the coins in desc order, then iterate through the coins"""
    if total <= 0:
        return 0
    for i in range(len(coins)):
        if coins[i] > total:
            return -1
    coins.sort(reverse=True)
    count = 0
    for i in range(len(coins)):
        count += total // coins[i]
        total = total % coins[i]
    if total != 0:
        return -1
    return count
