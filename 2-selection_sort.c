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
 * selection_sort - Sorts an array of integers in ascending order
 *	using the `Selection sort` algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			my_swap(array + i, min);
			print_array(array, size);
		}
	}
}
