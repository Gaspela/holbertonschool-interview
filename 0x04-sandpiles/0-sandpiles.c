#include "sandpiles.h"
/**
 * print_grid - print grid
 * @grid: grid
 * Return: nothing
 */
void print_grid(int grid[3][3])
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
/**
 * grid_sum - sum grid1 and grid2 = grid1
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: nothing
 */
void grid_sum(int grid2[3][3], int grid1[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid1[i][j] = grid2[i][j];
}
/**
 * check_grid - check the grid stable
 * @grid1: grid1
 * Return: 1 unstable, 0 stable
 */
int check_grid(int grid1[3][3])
{
    int row, col;

    for (row = 0; row < 3; row++)
        for (col = 0; col < 3; col++)
            if (grid1[row][col] > 3)
                return (1);
    return (0);
}
/**
 * fill_grid - 3x3 fill zeros
 * @grid2: grid2
 * Return: nothing
 */
void fill_grid(int grid2[3][3])
{
    int row, col;

    for (row = 0; row < 3; row++)
        for (col = 0; col < 3; col++) 
            grid2[row][col] = 0;
}
/**
 * sandpiles_sum - funtions sum grid1 grid2
 * @grid1: grid1
 * @grid2: grid2
 * Return: nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            grid1[i][j] = grid1[i][j] + grid2[i][j];
    }
    while (check_grid(grid1))
    {
        printf("=\n");
        print_grid(grid1);
        fill_grid(grid2);
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    grid2[i][j] += grid1[i][j] - 4;
                    if (i - 1 >= 0)
                        grid2[i - 1][j] += 1;
                    if (j - 1 >= 0)
                        grid2[i][j - 1] += 1;
                    if (i + 1 <= 2)
                        grid2[i + 1][j] += 1;
                    if (j + 1 <= 2)
                        grid2[i][j + 1] += 1;
                }
                else
                    grid2[i][j] += grid1[i][j];
            }
        }
        grid_sum(grid2, grid1);
    }
}
