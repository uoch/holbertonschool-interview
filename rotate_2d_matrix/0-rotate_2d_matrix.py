#!/usr/bin/python3
"""
Rotate 2D Matrix
"""

def rotate_2d_matrix(matrix):
    """rotate matrix 90"""
    mat90 = matrix.copy()
    colums = []
    k = 0
    for i in matrix:
        for j in range(len(i)):
            colums.append(matrix[j][k])
        k += 1
    mat = [colums[i:i+(len(matrix))]
           for i in range(0, len(colums), len(matrix))]
    for i in range(len(matrix)):
        matrix[i] = mat[i][::-1]
