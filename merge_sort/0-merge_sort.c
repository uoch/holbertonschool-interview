
#include <stdio.h>
#include <stdlib.h>
void rec_merge_sort(int *array, int *temp, size_t start, size_t end);

void merge(int *array, int *temp, size_t start, size_t mid, size_t end);

void print_array(const int *array, size_t size);

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

void rec_merge_sort(int *array, int *temp, size_t start, size_t end)
{
    size_t mid;
    if (start >= end)
        return;

    mid = start + ((end - start) / 2);
    rec_merge_sort(array, temp, start, mid);
    rec_merge_sort(array, temp, mid + 1, end);
    merge(array, temp, start, mid, end);
}

void merge(int *array, int *temp, size_t start, size_t mid, size_t end)
{
    size_t i = start, j = mid + 1, k = start;

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
