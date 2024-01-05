#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary_recursive - recursive function to search for a value
 * @array: array to search
 * @left: left index
 * @right: right index
 * @value: value to search for
 * Return: index of value or -1 if not found
 */

int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;
	int mid;

	if (right >= left)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);
		mid = left + (right - left) / 2;
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		if (array[mid] >= value)
			return (advanced_binary_recursive(array, left, mid, value));
		return (advanced_binary_recursive(array, mid + 1, right, value));
	}
	return (-1);
}
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (advanced_binary_recursive(array, 0, size - 1, value));
}
