#include "sort.h"



/**
 * merge - Merges two subarrays of an array
 *
 * @array: The array to be sorted
 * @left: The left subarray
 * @left_size: Number of elements in @left
 * @right: The right subarray
 * @right_size: Number of elements in @right
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);
    while (i < left_size && j < right_size)
    {
        if (left[i] < right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left_size)
    {
        array[k] = left[i];
        i++;
        k++;
    }
    while (j < right_size)
    {
        array[k] = right[j];
        j++;
        k++;
    }
    printf("[Done]: ");
    print_array(array, left_size + right_size);
}

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
