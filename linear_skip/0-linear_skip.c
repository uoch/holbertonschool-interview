#include <stdio.h>
#include <stdlib.h>
#include "search.h"
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the list
 * @value: Value to search for
 * Return: void
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list;
	skiplist_t *prev = NULL;
	if (list == NULL)
		return NULL;

	while (current != NULL && current->n < value)
	{
		prev = current;

		if (current->express == NULL)
		{
			while (current->next != NULL)
				current = current->next;
			break;
		}

		prev = current;
		current = current->express;
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev ? prev->index : 0, current->index);

	while (prev != NULL && prev->n <= value)
	{
		if (prev->n == value)
		{
			printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
			return prev;
		}
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		prev = prev->next;
	}

	return NULL;
}