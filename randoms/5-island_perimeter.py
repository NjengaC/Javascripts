#!/usr/bin/python3
"""
Perimeter finder
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid:
    """
    sides = 0
    count = 0

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                count = count + 1
                if j > 0 and grid[i][j-1] == 1:
                    sides = sides + 1
                if i > 0 and grid[i-1][j] == 1:
                    sides = sides + 1

    return count * 4 - sides * 2
