#include "main.h"
/**
 * _pow_recursion - function that returns the value of x
 * raised to the power of y.
 * @x: is the base number
 * @y: is the power value
 *
 * Return: the value of x to power y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}
