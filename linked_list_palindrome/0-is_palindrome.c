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
 * is_palindrome - Check if a singly linked list is a palindrome.
 * @head: Pointer to a pointer to the head of the linked list.
 *
 * Return: 1 if the linked list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    listint_t *temp = *head;
    size_t pa = len_linked_list(temp);

    if (pa <= 1)
    {
        return (1);
    }
    else
    {
        size_t re = (pa % 2 == 0) ? pa / 2 : (pa - 1) / 2;
        int first_half[re];
        int second_half[re];

        for (size_t i = 0; i < re; i++)
        {
            first_half[i] = temp->n;
            temp = temp->next;
        }

        if (pa % 2 != 0)
        {
            temp = temp->next;
        }

        temp = *head;

        for (size_t j = re; j < pa; j++)
        {
            second_half[j - re] = temp->n;
            temp = temp->next;
        }

        for (size_t k = 0; k < re; k++)
        {
            if (first_half[k] != second_half[k])
            {
                return (0);
            }
        }

        return (1);
    }
}
