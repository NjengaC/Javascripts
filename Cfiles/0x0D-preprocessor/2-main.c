#include <stdio.h>
/**
 * main - prints the name of file from which it was compiled
 *
 * Return: 0 always Success
 */

int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
