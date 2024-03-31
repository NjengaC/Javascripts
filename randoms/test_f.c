#include <unistd.h> /*for the write function*/
#include <stdlib.h>
#include "main.h"
char buffer[BUFFER];
int buffer_track;

void fill_number(int numb)
{
	char arr[32];
	int temp, i, length = 0;

	if (numb < 0)
	{
		temp = numb;
		numb = -numb;
	}
		
	while (numb != 0)
	{
		arr[length] = '0' + (numb % 10);
		numb /= 10;
		length++;
	}
	if (temp < 0)
	{
		arr[length] = '-';
		arr[length + 1] = '\0';
	}
	for (i = length - 1; i >= 0; i--)
	{
	fill_char_buffer(arr[i]);
	}
}

/**
 *  * fill_buffer - fills buffer with formated character
 *   * @c: character to fill buffer from
 *    *
 *     * Return: nothing
 *      */
void fill_char_buffer(char c)
{
	buffer[buffer_track] = c;
	if (buffer_track == BUFFER)
		flush_buffer();
	buffer_track++;
}
