#include "sort.h"

/**
 * swap - swap element in array
 * @a: first element
 * @b: second element
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - selection sort
 * @array: the array
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i != min)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
