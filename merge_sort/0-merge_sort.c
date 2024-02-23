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
	size_t i = start, j = mid + 1, k = start;

	if (array[mid] <= array[mid + 1])
		return;

	printf("Merging...\n");

	printf("[left]: ");
	print_array(array + start, mid - start + 1);
	printf("[right]: ");
	print_array(array + mid + 1, end - mid);

	while (i <= mid && j <= end)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= end)
		temp[k++] = array[j++];

	for (i = start; i <= end; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + start, end - start + 1);
}
