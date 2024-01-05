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

int advanced_binary(int *array, size_t size, int value){
	int left = 0;
	int right = size - 1;
	int mid = 0;
	int i = 0;

	if (array == NULL)
		return (-1);
	while (left <= right){
		printf("Searching in array: ");
		for (i = left; i <= right; i++){
			printf("%d", array[i]);
			if (i != right)
				printf(", ");
		}
		printf("\n");
		mid = (left + right) / 2;
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		else if (array[mid] >= value)
			right = mid;
		else
			left = mid + 1;
	}
	return (-1);
}