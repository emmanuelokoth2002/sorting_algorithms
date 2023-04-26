#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using sort algorithm
 *
 * @list: Pointer to the first element of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *curr;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;

		for (curr = *list; curr->next != NULL; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				temp = curr->next;
				curr->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = curr;
		temp->prev = curr->prev;
		if (curr->prev != NULL)
			curr->prev->next = temp;
		else
			*list = temp;
		curr->prev = temp;
		temp->next = curr;

		swapped = 1;
		print_list(*list);
	}
	}

	if (swapped == 0)
		break;

	swapped = 0;

	for (curr = curr->prev; curr != NULL; curr = curr->prev)
	{
		if (curr->n > curr->next->n)
		{
		temp = curr->next;
		curr->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = curr;
		temp->prev = curr->prev;
		if (curr->prev != NULL)
			curr->prev->next = temp;
		else
			*list = temp;
		curr->prev = temp;
		temp->next = curr;

		swapped = 1;
		print_list(*list);
		}
	}
	} while (swapped);
}
