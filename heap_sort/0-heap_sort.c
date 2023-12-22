#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * heapify - helper function to sort an array of integers
 * @array: array to sort in place
 * @size: size of the array
 * @i: i index
 * @total_size: total_size of the array
 */
void heapify(int *array, int size, int i, int total_size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int temp;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, total_size);
		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to sort in place
 * @size: size of the array
 */

void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (array == NULL || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
