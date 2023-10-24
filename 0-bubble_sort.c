#include "sort.h"

/**
 * my_swap - Swaps two integers.
 * @x: The first integer.
 * @y: The second integer.
 */
void my_swap(int *x, int *y)
{
	*x += *y;
	*y = *x - *y;
	*x -= *y;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *	using the `Bubble sort` algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t sorted = 0, i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				my_swap(array + j, array + j + 1);
				print_array(array, size);
				sorted = 1;
			}
		}
		if (!sorted)
			break;
	}
}
