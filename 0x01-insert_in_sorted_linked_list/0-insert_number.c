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
    
    current = *head;
    new = malloc(sizeof(listint_t));
    if (!head || !number || !new)
        return (NULL);

    while (current)
    {
        if (current->next && current->n > number)
        {
            new->next = current->next;
            new->n = current->n;
            current->next = new;
            current->n = number;
            current = new->next;
        }
        current = current->next;
    }

    return (new);
   }