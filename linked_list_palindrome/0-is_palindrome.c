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

    array = (int *)malloc((re + 1) * sizeof(int));

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
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to a pointer to the head of the list
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *curr = *head;
    listint_t *tail = NULL;

    while (curr != NULL)
    {
        tail = curr->next;
        curr->next = tail->next;
        tail->next = *head;
        *head = tail;
        curr = curr->next;
    }

    return (*head);
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
    listint_t *tail;
    size_t pa, re, k;
    int *first_half, *second_half;

    pa = len_linked_list(temp);
    tail = reverse_listint(head);
    if (pa <= 1)
    {
        return (1);
    }
    else
    {
        re = (pa % 2 == 0) ? pa / 2 : (pa - 1) / 2;

        first_half = fullfill_array(temp, re);
        second_half = fullfill_array(tail, re);
        for (k = 0; k < re; k++)
        {
            if (first_half[k] != second_half[k])
            {
                free(first_half);
                free(second_half);
                return (0);
            }
        }
        free(first_half);
        free(second_half);
        return (1);
    }
}
