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

	if (node1->next == node2)
	{
		node1->next = node2->next;
		node2->prev = node1->prev;
		node1->prev = node2;
		node2->next = node1;

	}
	else if (node2->next == node1)
	{
		node2->next = node1->next;
		node1->prev = node2->prev;
		node2->prev = node1;
		node1->next = node2;
	}
	else
	{
		listint_t *node1_prev = node1->prev;
		listint_t *node1_next = node1->next;

	if (node1_prev)
		node1_prev->next = node2;
	else
		*head = node2;

	if (node1_next)
		node1_next->prev = node2;
		node1->prev = node2->prev;
		node1->next = node2->next;
		node2->prev = node1_prev;
		node2->next = node1_next;
	}
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
