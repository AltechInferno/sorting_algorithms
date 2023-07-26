#include "sort.h"
/**
 * shell_sort - the shell sort algorithm
 * @array: the array
 * @size: the size of the array
 *
 * Description: working with the knuth sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t a, b;
	size_t gapp = 1;
	int item;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (gapp < (size / 3))
	{
		gapp = gapp * 3 + 1;
	}
	while (gapp >= 1)
	{
		for (a = gapp; a < size; a++)
		{
			for (b = a; b >= gapp && array[gapp] < array[b - gapp]; b -= gapp)
			{
				item = array[b];
				array[b] = array[b - gapp];
				array[b - gapp] = item;
			}
		}
		gapp = gapp / 3;
		print_array(array, size);
	}
}
