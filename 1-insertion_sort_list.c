#include "sort.h"

void swap(listint_t **head, listint_t *n1, listint_t *n2);
/**
 * swap - this swaps two nodes
 * @head: head node
 * @n1: first node
 * @n2: second node
 *
 * Return: void
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;

	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}

/**
 * insertion_sort_list - sorts doubly linked list with
 * insertion sort algorithm
 *
 * @list: list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *forward, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (forward = (*list)->next; forward &&
			forward->prev; forward = forward->next)
	{
		for (; forward && forward->prev && forward->n < forward->prev->n;
		     forward = forward->prev)
		{
			tmp = forward->prev;
			swap(list, tmp, forward);
			print_list(*list);
			forward = forward->next;
		}
	}
}
