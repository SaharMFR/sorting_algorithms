#include "sort.h"

/**
 * node_swap_ahead - Swaps a node in a listint_t doubly-linked list
 *	list of integers with the node ahead of it.
 * @list: The pointer to the head of the list.
 * @tail: The pointer to the tail of the list.
 * @shaker: The pointer to the current swapping node of the cocktail
 *	shaker algorithm.
 */
void node_swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev)
		(*shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;
	if (temp->next)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * node_swap_behind - Swaps a node in a listint_t doubly-linked
 *	list of integers with the node behind it.
 * @list: The pointer to the head of the list.
 * @tail: The pointer to the tail of the list.
 * @shaker: The pointer to the current swapping node of the cocktail
 *	shaker algorithm.
 */
void node_swap_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;
	if (temp->prev)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *	in ascending order using the `Cocktail shaker sort` algorithm.
 * @list: The pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (!list || !(*list) || !((*list)->next))
		return;

	for (tail = *list; tail->next;)
		tail = tail->next;

	while (!shaken_not_stirred)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				node_swap_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				node_swap_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
