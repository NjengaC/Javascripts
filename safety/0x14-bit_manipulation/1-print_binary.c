#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: number to print in binary
 * Return: nothing
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;
		if (current)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');

	}
	_putchar('\n');
}
