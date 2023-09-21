#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * len_linked_list - Calculate the length of a linked list.
 * @h: Pointer to the head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t len_linked_list(const listint_t *h)
{
    const listint_t *current;
    size_t n = 0;

    current = h;
    while (current != NULL)
    {
        current = current->next;
        n++;
    }

    return (n);
}

/**
 * free_array - Free memory for arrays.
 * @array: Pointer to the first array.
 * @array2: Pointer to the second array.
 * @size: Size of the arrays.
 */
void free_array(int *array, int *array2, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        array[i] = 0;
        array2[i] = 0;
    }

    free(array);
    free(array2);
}

/**
 * fullfill_array - Fill an array with values from a linked list.
 * @temp: Pointer to the linked list.
 * @re: Size of the array.
 *
 * Return: A pointer to the filled array.
 */
int *fullfill_array(listint_t *temp, size_t re)
{
    int *array;
    size_t i;

    array = (int *)malloc(re * sizeof(int));

    if (array == NULL)
    {
        return (NULL);
    }

    for (i = 0; i < re; i++)
    {
        array[i] = temp->n;
        temp = temp->next;
    }

    return (array);
}

/**
 * is_palindrome - Check if a singly linked list is a palindrome.
 * @head: Pointer to a pointer to the head of the linked list.
 *
 * Return: 1 if the linked list is a palindrome, 0 otherwise.
 */

int is_palindrome(listint_t **head)
{
    listint_t *temp = *head;
    size_t pa, re, k, j;
    int *first_half, *second_half;

    pa = len_linked_list(temp);

    if (pa <= 1)
    {
        return (1);
    }
    else
    {
        re = (pa % 2 == 0) ? pa / 2 : (pa - 1) / 2;

        first_half = fullfill_array(temp, re);

        if (pa % 2 != 0)
        {
            temp = temp->next;
        }

        temp = *head;

        second_half = (int *)malloc(re * sizeof(int));
        if (second_half == NULL)
        {
            free(first_half);
            return (0);
        }

        for (j = 0; j < re; j++)
        {
            second_half[j] = temp->n;
            temp = temp->next;
        }

        for (k = 0; k < re; k++)
        {
            if (first_half[k] != second_half[k])
            {
                free(first_half);
                free(second_half);
                return (0);
            }
        }

        free(second_half);
        return (1);
    }
}
