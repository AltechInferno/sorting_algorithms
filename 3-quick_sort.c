#include "sort.h"

/*prototypes. funcs will be defined later in this file*/
void sort_alg(int *arr, int left, int right, size_t size);
int split(int *arr, int left, int right, size_t size);

/**
  * split - this splits array
  * @arr: array
  * @left: the leftmost index
  * @right: the rightmost index
  * @size: the full array size
  * Return: the pivot index
  */
int split(int *arr, int left, int right, size_t size)
{
	int j, j2, pivot, tmp;

	pivot = arr[right];
	j = left;

	for (j2 = left; j2 < right; j2++)
	{
		if (arr[j2] < pivot)
		{
			if (j != j2)
			{
				tmp = arr[j2];
				arr[j2] = arr[j];
				arr[j] = tmp;
				print_array(arr, size);
			}
			j++;
		}
	}
	if (arr[j] != arr[right])
	{
		tmp = arr[j];
		arr[j] = arr[right];
		arr[right] = tmp;
		print_array(arr, size);
	}

	return (j);
}

/**
  * sort_alg - the recursive sorting algorithm
  * @arr: the array
  * @left: the leftmost index
  * @right: the rightmost index
  * @size: the full size of array
  */
void sort_alg(int *arr, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = split(arr, left, right, size);
		sort_alg(arr, left, pivot - 1, size);
		sort_alg(arr, pivot + 1, right, size);
	}
}

/**
  * quick_sort - the quicksort algorithm
  * @array: the array to be sorted
  * @size: the size of array
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	sort_alg(array, 0, size - 1, size);
}
