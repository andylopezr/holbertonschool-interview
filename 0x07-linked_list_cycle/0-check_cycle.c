#include "lists.h"
#include <stdlib.h>

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: list to check
 * Return: 0
 */

int check_cycle(listint_t *list)
{
	listint_t *first_step = list, *second_step = list;

	while (first_step && second_step && second_step->next)
	{
		first_step = first_step->next;
		second_step = second_step->next->next;
		if (first_step == second_step)
			return (1);
	}
	return (0);
}
