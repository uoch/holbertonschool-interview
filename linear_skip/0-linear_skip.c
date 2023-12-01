#include <stdio.h>
#include <stdlib.h>
#include "search.h"
/*

*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = list;
    skiplist_t *prev = NULL;
    if (list == NULL)
        return NULL;
    while (current->express != NULL && current->n < value)
    {
        prev = current;
        current = current->express;
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    }
    if (current->express == NULL)
    {
        printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);
        while (current->next != NULL)
        {
            printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
            if (current->n == value)
                return current;
            current = current->next;
        }
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        return NULL;
    }
    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);
    while (prev->next != NULL && prev->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return prev;
        prev = prev->next;
    }
    printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
    return NULL;
}