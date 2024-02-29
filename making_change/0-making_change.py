#!/usr/bin/python3
"""find the minimum numb of coins required to make change for a given total"""


def makeChange(coins, total):
    """first sort the coins in desc order, then iterate through the coins"""
    if total < 0 or not coins:
        return -1

    coins.sort(reverse=True)  # Sort coins in descending order

    count = 0
    for coin in coins:
        while total >= coin:
            total -= coin
            count += 1

    return count if total == 0 else -1
