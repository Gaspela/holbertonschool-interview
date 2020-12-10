#include "search_algos.h"
/**
 * print_array - print an array
 * @array: array
 * @first: size of array
 * @last: last element
*/
void print_array(int *array, int first, int last)
{
	int i;

	printf("Searching in array: ");
	for (i = first; i < last; i++)
		printf("%d, ", array[i]);
	printf("%d", array[i]);
	printf("\n");
}

/**
 * recur_binary_searc - recursive advanced binary search
 * @array: array  to search
 * @first: first element of array
 * @last: last element of array
 * @value: value to find
 * Return: element in array
*/
int recur_binary_searc(int *array, size_t first, size_t last, int value)
{
	size_t i;

	if (first < last)
	{
		i = first + (last - first) / 2;
		print_array(array, (int)first, (int)last);
		if (array[i] >= value)
			return (recur_binary_searc(array, first, i, value));
		else
			return (recur_binary_searc(array, i + 1, last, value));
		return ((int)(i));
	}
	if (array[first] == value)
		return (first);
	print_array(array, (int)first, (int)last);
	return (-1);
}
/**
 * advanced_binary - check array
 * @array: array to search
 * @size: size of array
 * @value: value to find
 * Return: element in array
*/
int advanced_binary(int *array, size_t size, int value)
{
	size_t first;
	size_t last;

	if (!array)
		return (-1);

	first = 0;
	last = size - 1;
	return (recur_binary_searc(array, first, last, value));
}
