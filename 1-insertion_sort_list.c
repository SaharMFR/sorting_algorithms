#include "sort.h"

/**
 * my_node_swap - Swaps two nodes in a doubly linked list.
 * @h: The pointer to the head of the list.
 * @n1: The first node.
 * @n2: The second node.
 */
void my_node_swap(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *	in ascending order using `Insertion sort` algorithm.
 * @list: The pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *temp;

	if (!list ||!(*list) || !((*list)->next))
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert && i->n < insert->n)
		{
			my_node_swap(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
