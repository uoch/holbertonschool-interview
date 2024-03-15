#include "sort.h"

/**
 * getMax - Finds the maximum value in an array.
 *
 * This function iterates through the array to find the maximum value.
 *
 * @array: The array to find the maximum value from.
 * @size: The number of elements in the array.
 * Return: The maximum value found in the array.
 */

int getMax(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

/**
 * countingSort - Performs counting sort based on digit represented by exp.
 *
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 * @exp: The position of the digit to be considered (1, 10, 100, ...).
 */
void countingSort(int *array, size_t size, int exp)
{
	size_t i;
	int *output;
	int count[10] = {0};

	output = (int *)malloc(size * sizeof(int));
	if (output == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i > 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");

	free(output);
}

/**
 * radix_sort - Sorts an arr of int in ascend order using the Radix sort algo.
 *
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
		countingSort(array, size, exp);
}
