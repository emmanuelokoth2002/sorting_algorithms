#include "sort.h"

/**
 * get_gap - compute gap using knuth sequence
 * @size: array size
 * Return: the gap
 */

size_t get_gap(size_t size)
{
	size_t interval = 1;

	while (interval < size)
		interval = interval * 3 + 1;
	return ((interval - 1) / 3);
}
/**
 * shell_sort - Sorts an array of integers in ascending order
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i, j;
	int temp;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		printf("Interval %lu -> ", interval);
	for (i = interval; i < size; i++)
	{
		temp = array[i];
		for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			array[j] = array[j - interval];
		array[j] = temp;
	}
	print_array(array, size);
	interval = (interval - 1) / 3;
	}
}
