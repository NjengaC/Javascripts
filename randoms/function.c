#include "main.h"
#include <unistd.h>
/**
 * _memset - fill a block of memory with a specific value
 * @s: starting address of memory to be filled
 * @b: the desired value
 * @n: number of bytes to be changed
 *
 * Return: changed array with new value for n bytes
 */
void _memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}
	return (longi);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *  _puts - prints a string, followed by a new line, to stdout
 *   @str: string to print
 *
 *   Return: nothing
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
}

/**
 * flush_buffer - writes out to stdout when conditions are met
 * Return: nothing
 */
void flush_buffer(void)
{
	_puts(buffer);
	_memset(buffer, 0, sizeof(buffer));
	buffer_track = 0;
}
