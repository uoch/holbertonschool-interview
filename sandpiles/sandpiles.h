#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdbool.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
bool toppel_check(int grid[3][3]);
void do_toppel(int grid[3][3]);
void print(int grid[3][3]);

#endif /* SANDPILES_H */
