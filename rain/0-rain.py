#!/usr/bin/python3
"""rain """

def comapre(wall, wall2):
    """compare"""
    return min(wall, wall2) * abs(wall - wall2)

def rain(walls):
    total_rain = 0
    count = 0

    for wall in walls:
        if wall > 0:
            for wall2 in walls:
                if wall2 == 0:
                    count += 1
                else:
                    total_rain += comapre(wall, wall2) * count
                    count = 0
                    break

    return total_rain
        

