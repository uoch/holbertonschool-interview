#ifndef __SORT_H_
#define __SORT_H_
#include <stdio.h>
#include <stdlib.h>


void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size);



#endif