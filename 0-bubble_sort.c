#include "sort.h"

void
swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void
bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int ssw;

	for (j = 0; j < size; j++)
	{
		ssw = 0;
		for (i = 0; i < size - j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				ssw = 1;
				print_array(array, size);
			}
		}
		if (ssw == 0)
			break;
	}
}
