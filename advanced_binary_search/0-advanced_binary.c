#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
/**
 * advanced_binary_recursive - recursive function to search for a value
 * @array: array to search
 * @value: value to search for
 * @left: left index
 * @right: right index
 * Return: index of value or -1 if not found
 */
int advanced_binary_recursive(int *array, int value, int left, int right)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;

		printf("Searching in array: ");
		for (int i = left; i <= right; ++i)
		{
			printf("%d", array[i]);
			if (i < right)
			{
				printf(", ");
			}
		}
		printf("\n");

		if (array[mid] == value)
		{
			return mid;
		}
		else if (array[mid] > value)
		{
			return advanced_binary_recursive(array, value, left, mid - 1);
		}
		else
		{
			return advanced_binary_recursive(array, value, mid + 1, right);
		}
	}
	return -1;
}

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
	{
		return -1;
	}

	return advanced_binary_recursive(array, value, 0, size - 1);
}