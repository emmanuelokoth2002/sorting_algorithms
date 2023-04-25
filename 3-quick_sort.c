#include "sort.h"

/**
 * swap - swap elements and print new array
 * @array: pointer to array
 * @size: the size of the array
 * @a: address of first element
 * @b: address of second element
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
		print_array((const int *)array, size);
	}
}

/**
 * partition - partitions the array
 * @array: pointer to array
 * @size: the size 
 * @l: the low index 
 * @h: the high index of the sort range
 * Return: index of partition point
 */
size_t partition(int *array, size_t size, ssize_t l, ssize_t h)
{
	int i, j, pivot = array[h];

	for (i = j = l; j < h; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[h]);

	return (i);
}

/**
 * quicksort - quicksorts 
 * @array: pointer to array
 * @size: the size of  array
 * @l: the low index
 * @h: the high index
 */
void quicksort(int *array, size_t size, ssize_t l, ssize_t h)
{
	if (l < h)
	{
		size_t p = partition(array, size, l, h);

		quicksort(array, size, l, p - 1);
		quicksort(array, size, p + 1, h);
	}
}

/**
 * quick_sort - quicksort algorithm
 * @array: array's pointer
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;
	quicksort(array, size, 0, size - 1);
}
