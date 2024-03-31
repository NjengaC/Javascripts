#include "main.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * is_digit - checks if a string contains digits only
 * @s: string to check
 *
 * Return: 0 if there is a not digit else 1
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/**
 * _strlen - evaluates string length
 * @s: string for which length is checked
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * errors - handles errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int x, y, len, i, k, m, n, *r, a = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !is_digit(s1) || !is_digit(s2))
		errors();
	x = _strlen(s1);
	y = _strlen(s2);
	len = x + y + 1;
	r = malloc(sizeof(int) * len);
	if (!r)
		return (1);
	for (i = 0; i <= x + y; i++)
		r[i] = 0;
	for (x = x - 1; x >= 0; x--)
	{
		m = s1[x] - '0';
		k = 0;
		for (y = _strlen(s2) - 1; y >= 0; y--)
		{
			n = s2[y] - '0';
			k += r[x + y + 1] + (m * n);
			r[x + y + 1] = k % 10;
			k /= 10;
		}
		if (k > 0)
			r[x + y + 1] += k;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (r[i])
			a = 1;
		if (a)
			_putchar(r[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(r);
	return (0);
}
