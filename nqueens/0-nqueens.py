#!/usr/bin/python3
import sys


def is_safe(board, row, col):
    """Check if it is safe to place a queen at board[x][y]"""
    for i in range(row):
        if board[i] == col or abs(board[i] - col) == abs(i - row):
            return False
    return True


def solve_nqueens(n):
    """Solve the n queens problem and print the number of solutions"""
    result = []

    def backtrack(board, row, n):
        if row == n:
            result.append([[i, board[i]] for i in range(n)])
            return
        for col in range(n):
            if is_safe(board, row, col):
                board[row] = col
                backtrack(board, row + 1, n)
                board[row] = -1

    board = [-1] * n
    backtrack(board, 0, n)
    return result


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
        if n <= 0:
            print("N must be a positive integer.")
            sys.exit(1)
        if n < 4:
            print("N must be at least 4")
            sys.exit(1)
        solutions = solve_nqueens(n)
        print(solutions)
    except ValueError:
        print("N must be a number")
        sys.exit(1)
