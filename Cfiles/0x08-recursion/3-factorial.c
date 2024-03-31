#include "main.h"
/**
 * factorial - returns the factorial of a number
 * @n: is the number
 *
 * Return: factorial always (Success) otherwise -1 (error)
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
