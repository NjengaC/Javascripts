#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * convert_binary - prints binary equivalent of a decimal number
 * @n: number to print in binary
 * Return: a string of binary characters
 */
char* convert_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;
	char *string;

	string = malloc(64 + 1); 
	if (string == NULL)
		return(NULL); 

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			string[count] = '1';
			count++;
		}
		else if (count)
		{
			string[count] = '0';
			count++;
		}
	}
	if (!count)
	{
		string[count] = '0';
		count++;
	}
	string[count] = '\0';
//	printf("%s\n", string);
return (string);
}
