#!/usr/bin/python3



def makeChange(coins, total):
    for i in range(len(coins)):
        if coins[i] > total:
            coins.pop(i)
    coins.sort(reverse=True)
    count = 0
    for i in range(len(coins)):
        count += total // coins[i]
        total = total % coins[i]
    if total != 0:
        return -1
    return count