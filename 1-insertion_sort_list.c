#include "sort.h"

void swap(listint_t **head, listint_t *node1, listint_t *node2);
/**
 * swap - this swaps two nodes
 * @head: head node
 * @node1: first node
 * @node2: second node
 *
 * Return: void
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (node1 == node2)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*head = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
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
