#include "sort.h"

/**
 * bubble_sort - Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int temp = 0, swap_track = 1, size_cpy = size;

	if (size < 2)
		return;

	while (swap_track)
	{
		swap_track = 0;
		for (i = 0; i < size; i++)
		{
			if ((array[i] > array[i + 1]))
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size_cpy);
				swap_track++;
			}

			if (i == size - 1 && (array[i - 1] < array[i]))
				size--;
		}
	}

}
