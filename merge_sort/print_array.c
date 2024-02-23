#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
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
