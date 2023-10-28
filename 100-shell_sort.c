#include "sort.h"

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
 * shell_sort - Sorts an array of integers in ascending order using
 *	`Shell sort` algorithm , using the `Knuth sequence`.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (!array || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				my_swap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
