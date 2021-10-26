#include "sort.h"

/**
 * cocktail_sort_list - sort a list using
 * cocktail_sort algorithm
 * @list: pointer to the list head
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *current, *new_head;
	int swapped = 1, i = 0, j, e = 0;

	if (!list || !(*list) || !(*list)->next)
		return;
	start = *list, current = start;
	while (swapped == 1)
	{
		swapped = 0;
		while (current && current->next)
		{
			if (current->n > current->next->n)
			{
				end = current, current = current->next;
				new_head = swap_nodes(current->prev, current, *list), swapped = 1;
				if (new_head != NULL)
					*list = new_head, start = *list;
			} else
				current = current->next, end = current;
		}
		if (swapped == 0)
			break;
		for (j = 0; j < i; j++)
			start = start->next;
		swapped = 0, e++;
		while (end && end->next != NULL)
			end = end->next;
		for (j = 0; j < e; j++)
			end = end->prev;
		current = end;
		while (current && current->prev && current != start->prev)
		{
			if (current->n > current->next->n)
			{
				new_head = swap_nodes(current, current->next, *list), swapped = 1;
			}
			current = current->prev;
		}
		i++, start = start->next;
	}
}
