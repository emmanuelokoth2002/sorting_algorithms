#include "sort.h"

/**
 * move_to_head - Get list's head
 * @node: node in list
 * Return: head of list
 */

listint_t *move_to_head(listint_t *node)
{
	while (node->prev)
		node = node->prev;
	return (node);
}
/**
 * insertion_sort_list - sorts a doubly linked
 * ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *buff, *ptr;

	if (list == NULL)
		return;
	temp = move_to_head(*list);

	for (temp = temp->next; temp;)
	{
		buff = temp->next;
		while (temp->prev && temp->n < temp->prev->n)
		{
			ptr = temp->prev;
			ptr->next = temp->next;
			temp->prev = ptr->prev;
			ptr->prev = temp;
			temp->next = ptr;
			if (ptr->next)
				ptr->next->prev = ptr;
			if (temp->prev)
				temp->prev->next = temp;
			print_list(move_to_head(*list));
		}
		temp = buff;
	}
	*list = move_to_head(*list);
}
