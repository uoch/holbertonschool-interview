#include "sandpiles.h"
/**
 * toppel_check - sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 *
 * Return: true if cell is greater than 3
 */
void print(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
bool toppel_check(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                return true;
            }
        }
    }
    return false;
}
/**
 * do_toppel - topple the cell to her neighbors
 * @grid: sum of two sandpiles
 *
 * Return: void
 */
void do_toppel(int grid[3][3])
{
    int i, j;
    if (toppel_check(grid) == false)
    {
        return;
    }
    else
    {
        printf("=\n");
        print(grid);
        printf("\n");
        while (toppel_check(grid) == true)
        {
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {

                    if (grid[i][j] > 3)
                    {
                        grid[i][j] -= 4;
                        if (i - 1 >= 0)
                            grid[i - 1][j] += 1;
                        if (i + 1 < 3)
                            grid[i + 1][j] += 1;
                        if (j - 1 >= 0)
                            grid[i][j - 1] += 1;
                        if (j + 1 < 3)
                            grid[i][j + 1] += 1;
                    }
                }
            }
            printf("=\n");
            print(grid);
            printf("\n");
        }
    }
}

/**
 * sandpiles_sum - sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int gridsum[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            gridsum[i][j] = grid1[i][j] + grid2[i][j];
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] = gridsum[i][j];
        }
    }

    do_toppel(grid1);
}