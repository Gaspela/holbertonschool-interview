#include "sort.h"

/**
 * swap - Swap the the position of two elements
 * @a: pointer a
 * @b: pointer b
 * @array: array
 * @n: size of array
*/
void swap(int *a, int *b, int *array, size_t n)
{

	int temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, n);
}

/**
 * heap - Find and order distribution
 * @arr: array
 * @n: actual size
 * @i: actual position
 * @size: total size
*/
void heap(int *arr, int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest], arr, size);
		heap(arr, n, largest, size);
	}
}

/**
 * heap_sort - Heap sort algorithm
 * @array: array
 * @size: number of elements in array
*/
void heap_sort(int *array, size_t size)
{

	size_t i;

	if (array == NULL)
		return;

	for (i = size / 2; i > 0; i--)
		heap(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		heap(array, i, 0, size);
	}
}
