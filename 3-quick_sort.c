#include "sort.h"

void my_swap(int *x, int *y);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * my_swap - Swaps two integers.
 * @x: The first integer.
 * @y: The second integer.
 */
void my_swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto_partition - Orders a subset of an array of integers taking
 *	last element as pivot.
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset array to order.
 * @end: The ending index of the subset array to order.
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int *pivot, above, below;

	pivot = array + end;
	for (above = below = start; below < end; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				my_swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		my_swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implements the quicksort algorithm recursively.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * @start: The starting index of the array partition to order.
 * @end: The ending index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = lomuto_partition(array, size, start, end);
		lomuto_sort(array, size, start, part - 1);
		lomuto_sort(array, size, part + 1, end);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *	using the quicksort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
