#include "function_pointers.h"

/**
 * int_index - serches for an int
 * @array: array
 * @size: number of elements in the array
 * @cmp: pointer to function
 * Return: 0 on success else -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
