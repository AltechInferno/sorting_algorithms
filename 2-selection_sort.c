#include "sort.h"
/**
 * selection_sort - the selection sort algorithm
 * @array: array
 * @size: size of the array
 * Return: NULL
 */
void selection_sort(int *array, size_t size)
{
	unsigned int m, n, min, holder;

	if (size < 2)
		return;
	for (m = 0; m < size - 1; m++)
	{
		min = m;
		for (n = m + 1; n < size; n++)
		{
			if (array[n] < array[min])
			{
				min = n;
			}
		}
		if (min != m)
		{
			holder = array[m];
			array[m] = array[min];
			array[min] = holder;
			print_array(array, size);
		}
	}
}
