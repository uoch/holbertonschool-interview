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
        return NULL;
    new->n = number;
    new->next = NULL;

    temp = *head;                         
    if (temp == NULL || temp->n > number)
    {
        new->next = temp;
        *head = new;
        return new;
    }

    while (temp->next != NULL && temp->next->n <= number)
    {
        temp = temp->next;
    }

    new->next = temp->next;
    temp->next = new;
    return new;
}
