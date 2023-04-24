#include "sort.h"

/**
 * swap - swap two elements
 * @a: first element
 * @b: second elemtn
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sort an array, ascending order, Bubble sort
 * @array: array of integers
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, y;

	if (size == 0 || array == NULL)
		return;

	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				swap(&array[y], &array[y + 1]);
				print_array(array, size);
			}
		}
	}
}
