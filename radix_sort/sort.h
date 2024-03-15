#ifndef _SORT_H_
#define _SORT_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
int getMax(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);

#endif
