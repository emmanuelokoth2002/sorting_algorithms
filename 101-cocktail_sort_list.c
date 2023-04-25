#include "sort.h"

/**
 * swap_nodes - swap nodes
 * @list: pointer list
 * @node: pointer node
 */

void swap_nodes(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;

	if (node->next->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}

/**
 * get_length - compute  of nodes in list
 * @list: the double list
 * Return: Number of nodes
 */

listint_t *get_length(listint_t *list)
{
	listint_t *curr = list;

	while (curr->next != NULL)
		curr = curr->next;

	return (curr);
}

/**
 * cocktail_sort_list - sort doubly linked list
 * @list: pointer to list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *left_limit = NULL, *right_limit = NULL;
	int cycle_type = INCREMENT;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = *list;
	left_limit = curr;
	right_limit = get_length(*list);

	while (left_limit != right_limit)
	{
		if (curr->n == curr->next->n)
			break;
		else if (curr->n > curr->next->n && cycle_type == INCREMENT)
			swap_nodes(list, curr), print_list(*list);
		else if (curr->next->n < curr->n && cycle_type == DECREMENT)
			swap_nodes(list, curr), curr = curr->prev, print_list(*list);
		else if (cycle_type == INCREMENT)
			curr = curr->next;
		else if (cycle_type == DECREMENT)
			curr = curr->prev;

		if (cycle_type == DECREMENT && curr->next == left_limit)
		{
			cycle_type = INCREMENT;
			curr = curr->next;
		}

		if (cycle_type == INCREMENT && curr->prev == right_limit)
		{
			right_limit = right_limit->prev;
			cycle_type = DECREMENT;
			curr = curr->prev;
		}
	}
}
