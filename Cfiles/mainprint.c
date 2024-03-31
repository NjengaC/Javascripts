#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
char buffer[BUFFER];
int buffer_track = 0;
/**
 * fill_char_buffer - fills buffer with formated character
 * @c: character to fill buffer from
 *
 * Return: nothing
 */
void fill_char_buffer(char c)
{
	buffer[buffer_track] = c;

	if (buffer_track == BUFFER)
		flush_buffer();
	buffer_track++;
}
/**
 * fill_number - fills buffer with converted number
 * @numb: number
 * Return: nothing
 */
void fill_number(int numb)
{
	char arr[32];
	int temp = 1, i, length = 0;

	if (numb < 0)
	{
		temp = 0;
		numb = (numb * -1);
	}
	while (numb != 0)
	{
		arr[length] = '0' + (numb % 10);
		numb /= 10;
		length++;
	}

	if (temp == 0)
	{
		arr[length] = '-';
		length++;
	}

	for (i = length - 1; i >= 0; i--)
	{
		fill_char_buffer(arr[i]);
	}
}
/**
 * fill_string_to_buffer - fills buffer with contents of a formated string
 * @strn: string to fill from
 *
 * Return: nothing
 */
void fill_string_to_buffer(char *strn)
{
	while (*strn != '\0')
	{
		fill_char_buffer(*strn);
		strn++;
	}
}
/**
 * check_speci_tan - checks char conversion specifier and calls relevant function
 * @
 * Return:
 */
void check_speci_tna(char t, va_list args)
{
	va_start (args, format);
	if (t == 'c')
	{
		fill_char_buffer(va_arg(args, char));
	
	}
	if (t == 's')
	{
		fill_string_to_buffer(va_arg(args, char*));
	}
	if (t == 'i' || t == 'd')
	{
		fill_number(va_arg(args, int));
	}
	if (t == 'b')
	{
		fill_binary(va_arg(args, unsigned int));
	}
}
/**
 * _printf - fills buffer with charactes in formated form
 * @format: string containing characters
 *
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	char n;
	char *str;
	int printed_char, num;

	//va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				check_speci_tna(*format, va_list args);
				case '%':
					buffer[buffer_track++] = '%';
					break;
				default:
					buffer[buffer_track++] = '%';
			}
		}
		else
			fill_char_buffer(*format);
		format++;
	}
	printed_char = buffer_track;
	flush_buffer();
	return (printed_char);
}
