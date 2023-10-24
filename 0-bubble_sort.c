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
 * bubble_sort - Sorts an array of integers in ascending order
 *	using the `Bubble sort` algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t sorted = 0, i, temp = size;

	if (!array || size < 2)
		return;

	while (!sorted)
	{
		sorted = 1;
		for (i = 0; i < temp - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				my_swap(array + i, array + i + 1);
				print_array(array, size);
				sorted = 0;
			}
		}
		temp--;
	}
}
