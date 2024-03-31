#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of integers
 * @min: smmallest integer
 * @max: largest integer
 *
 * Return: pointer to the newly created array
 */

int *array_range(int min, int max)
{
	int i;
	int *ray;
	int range;

	if (min > max)
		return (NULL);

	range = max - min + 1;
	ray = malloc(sizeof(int) * range);

	if (ray == NULL)
		return (NULL);

	for (i = 0; min <= max; i++)
	{
		ray[i] = min;
		min++;
	}
	return (ray);
}
