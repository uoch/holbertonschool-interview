#include <stdio.h>
#include <stdlib.h>

void rec_merge_sort(int *array, int *temp, size_t start, size_t end);
void merge(int *array, int *temp, size_t start, size_t mid, size_t end);
void print_array(const int *array, size_t size);

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	rec_merge_sort(array, temp, 0, size - 1);
	free(temp);
}

/**
 * rec_merge_sort - Recursively sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @temp: A temporary array to store the sorted subarray
 * @start: The starting index of the subarray
 * @end: The ending index of the subarray
 */
void rec_merge_sort(int *array, int *temp, size_t start, size_t end)
{
	size_t mid;

	if (start >= end)
		return;

	if ((end - start) % 2)
		mid = start + (end - start) / 2;
	else
		mid = start + (end - start) / 2 - 1;

	rec_merge_sort(array, temp, start, mid);
	rec_merge_sort(array, temp, mid + 1, end);
	if (array[mid] > array[mid + 1])
		merge(array, temp, start, mid, end);
}

/**
 * merge - Merges two subarrays of an array
 * @array: The array to be sorted
 * @temp: A temporary array to store the sorted subarray
 * @start: The starting index of the subarray
 * @mid: The middle index of the subarray
 * @end: The ending index of the subarray
 */
void merge(int *array, int *temp, size_t start, size_t mid, size_t end)
{
	size_t left_index = start;
	size_t right_index = mid + 1;
	size_t temp_index = start;
	size_t i;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start + 1);
	printf("[right]: ");
	print_array(array + mid + 1, end - mid);

	while (left_index <= mid && right_index <= end)
	{
		if (array[left_index] <= array[right_index])
		{
			temp[temp_index++] = array[left_index++];
		}
		else
		{
			temp[temp_index++] = array[right_index++];
		}
	}

	while (left_index <= mid)
	{
		temp[temp_index++] = array[left_index++];
	}

	while (right_index <= end)
	{
		temp[temp_index++] = array[right_index++];
	}

	for (i = start; i <= end; i++)
	{
		array[i] = temp[i];
	}

	printf("[Done]: ");
	print_array(array + start, end - start + 1);
}
