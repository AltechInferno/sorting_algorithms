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
void swap(listint_t **head, listint_t *n1, listint_t *n2)
{
	listint_t *prev, *next;

	prev = n1->prev;
	next = n2->next;

	if (prev != NULL)
		prev->next = n2;
	else
		*head = n2;

	n1->prev = n2;
	n1->next = next;
	n2->prev = prev;
	n2->next = n1;
	if (next)
		next->prev = n1;
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
