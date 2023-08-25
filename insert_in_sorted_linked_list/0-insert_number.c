#include "lists.h"
/*
 * intsert_node - insert node into head
 * @head: head of linked list
 * @number: number to insert
 **/
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *temp;

    if (head == NULL)
        return NULL;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return NULL; // Return NULL if memory allocation fails

    new->n = number; // Assign number to new node
    new->next = NULL;

    temp = *head;                         // Assign head to head of linked list
    if (temp == NULL || temp->n > number) // If head is NULL or head is greater than number
    {
        new->next = temp;
        *head = new;
        return new;
    }

    while (temp->next != NULL && temp->next->n <= number) // Loop through linked list
    {
        temp = temp->next;
    }

    new->next = temp->next; // Assign new node to next node
    temp->next = new;
    return new;
}
