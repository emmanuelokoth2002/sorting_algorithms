#include "sort.h"

/**
 * get_gap - compute gap using knuth sequence
 * @size: array size
 * Return: the gap
 */

size_t get_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = gap * 3 + 1;
	return ((gap - 1) / 3);
}

/**
 * shell_sort - sort array, ascending, shell sort, knuth sequence
 * @array: pointer to array
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t x, gap = 1, y;
	int temp;

	if (array == NULL || size == 0)
		return;

	for (gap = get_gap(size); gap; gap = (gap - 1) / 3)
	{
		for (x = gap; x < size; x++)
		{
			temp = array[x];
			for (y = x; y >= gap && array[y - gap] > temp; y -= gap)
				array[y] = array[y - gap];
			array[y] = temp;
		}
		print_array(array, size);
	}
}
