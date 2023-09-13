#include "sort.h"

void swap(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

size_t
partition(int *arr, size_t low, size_t high, size_t size)
{
int pivot = arr[high];
size_t i = (low - 1);
size_t j;

for (j = low; j <= high; j++)
{
	if (arr[j] < pivot)
	{
		i++;
		if (i != j)
		{
			swap(&arr[i],&arr[j]);
			print_array(arr, size);
		}   
	}
}
if (arr[i + 1] != arr[high])
{
	swap(&arr[i + 1],&arr[high]);
	print_array(arr, size);
}
return (i + 1); 
}

void
qs_recursive(int *array, int first, int last, size_t size)
{
int piv;

if (first < last)
{
	piv = partition(array, first, last, size);

	qs_recursive(array, first, piv - 1, size);
	qs_recursive(array, piv + 1, last, size);
}
}

void
quick_sort(int *array, size_t size)
{
size_t f = 0;
size_t l = size - 1;

qs_recursive(array, f, l, size);
}
