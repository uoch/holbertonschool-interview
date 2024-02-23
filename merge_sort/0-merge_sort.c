#include "sort.h"


/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in @array

*/
void merge_sort(int *array, size_t size)
{
    int *temp;
    size_t i;
    if (size < 2)
        return;
    temp = malloc(size * sizeof(int));
    if (temp == NULL)
        return;
    for (i = 0; i < size; i++)
        temp[i] = array[i];
    merge_sort(temp, size / 2);
    merge_sort(temp + size / 2, size - size / 2);
    printf("Merging...\n");
    printf("[left]: ");
    print_array(temp, size / 2);
    printf("[right]: ");
    print_array(temp + size / 2, size - size / 2);
    merge(array, temp, size / 2, temp + size / 2, size - size / 2);
    free(temp);
}
