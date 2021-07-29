#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * *insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: node with number to insert in ordered list
 *
 * Return: address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;
    int key = 0;
    
    current = *head;
    new = malloc(sizeof(listint_t));
    if (!number || !new)
        return (NULL);
    
    new->n = number;
    new->next = NULL;
    if (!*head)
        *head = new;

    else
    {
        while (current)
        {
            if (current->next && current->n > number && key == 0)
            {
                new->next = current->next;
                new->n = current->n;
                current->next = new;
                current->n = number;
                current = new->next;
                key = 1;
            }
            current = current->next;
        }

        if (key == 0)
        {
            current = *head;
            while (current->next)
                current = current->next;
            current->next = new;
        }
    }
    return (new);
}