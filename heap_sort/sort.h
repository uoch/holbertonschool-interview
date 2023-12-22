#ifndef _SORT_H_
#define _SORT_H_
#include <stddef.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, int size, int i, int total_size);


#endif /* _SORT_H_ */
