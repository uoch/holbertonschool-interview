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
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to a pointer to the head of the list
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    if (head == NULL || *head == NULL)
        return NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;

    return *head;
}
/**
 * half_linked_list - Calculate the half of a linked list.
 * @head: Pointer to the head of the linked list.
 * Return: The half of the linked list.
 */
listint_t *half_linked_list(listint_t *head)
{
    listint_t *temp = head;
    size_t pa, re, k;

    pa = len_linked_list(temp);
    re = (pa % 2 == 0) ? pa / 2 : (pa - 1) / 2;
    for (k = 0; k < re; k++)
    {
        temp = temp->next;
    }
    return temp;
}
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: Pointer to the head of the linked list.
 * Return: 1 if it is a palindrome, 0 if it is not a palindrome.
 */
int is_palindrome(listint_t **head)
{
    listint_t *temp = *head;
    listint_t *tail, *half;
    size_t pa, re, k, m;
    int *first_half, *second_half;

    pa = len_linked_list(temp);
    tail = reverse_listint(&temp);
    half = half_linked_list(tail);

    if (pa <= 1)
    {
        return (1);
    }
    else
    {
        re = (pa % 2 == 0) ? pa / 2 : (pa - 1) / 2;

        first_half = fullfill_array(temp, re);
        second_half = fullfill_array(half, re);
        for (k = 0; k < re; k++)
        {
            m = re;
            if (first_half[k] != second_half[m - k - 1])
            {
                free(first_half);
                free(second_half);
                return (0);
            }
        }
        // No need to free first_half and second_half here.
        return (1);
    }
}
