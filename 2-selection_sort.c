#include "sort.h"

/**
 * swap - swap element in array
 * @a: first element
 * @b: second element
 */
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
/**
 * selection_sort - sort array, ascending, selection sort
 * @array: the array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
	min_idx = i;
	for (j = i + 1; j < size; j++)
	{
		if (array[j] < array[min_idx])
		{
			min_idx = j;
		}
	}
	swap(&array[min_idx], &array[i]);
        for (j = 0; j < size; j++)
	{
		printf("%d", array[j]);
		if (j != size - 1)
			printf(", ");
	}
	printf("\n");
	}
}
