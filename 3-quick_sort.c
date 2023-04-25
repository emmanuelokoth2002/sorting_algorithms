#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the
 *              quicksort algorithm with Lomuto partition scheme
 * @array: the array of integers to be sorted
 * @size: the size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - helper function that performs the quicksort algorithm recursively
 * @array: the array of integers to be sorted
 * @low: the starting index of the partition to be sorted
 * @high: the ending index of the partition to be sorted
 * @size: the size of the array
 * Return: void
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = partition(array, low, high, size);

        quicksort(array, low, pi - 1, size);
        quicksort(array, pi + 1, high, size);
    }
}

/**
 * partition - helper function that partitions the array and returns the pivot
 *
 * @array: the array of integers to be sorted
 * @low: the starting index of the partition to be sorted
 * @high: the ending index of the partition to be sorted
 * @size: the size of the array
 *
 * Return: the pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }

    swap(&array[i + 1], &array[high]);
    print_array(array, size);

    return (i + 1);
}

/**
 * swap - helper function that swaps two elements in an array
 *
 * @a: a pointer to the first element
 * @b: a pointer to the second element
 *
 * Return: void
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
