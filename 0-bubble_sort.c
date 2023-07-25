#include "sort.h"
void swap(int *array, int before, int after, int size);
/**
 * bubble_sort - this algorithm implements the bubble sort
 * @array: array
 * @size: the size of the array
 * Return: null
 */

void bubble_sort(int *array, size_t size)
{
	int ct;
	unsigned int j, b;

	if (size < 2)
		return;
	ct = 0;
	for (b = 0; b < size - 1; b++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1, size);
				ct++;
			}
		}
		if (ct < 1)
		{
			break;
		}
		ct = 0;
	}
}
/**
 * swap - this swaps in two places
 * @array: array
 * @before: first index
 * @after: second index
 * @size: size of the array
 * Return: null
 */
void swap(int *array, int before, int after, int size)
{
	int val;

	val = array[after];
	array[after] = array[before];
	array[before] = val;
	print_array(array, size);
}
