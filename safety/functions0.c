#include "shell.h"
/**
 * _strchr - function checks occurence of a character
 * @s: name of string containing character
 * @c: character to locate
 *
 * Return: always 0 (Success)
 */

char *_strchr(char *s, char c)

{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
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
 * _strdup - duplicates content of a string
 * @str: string to duplicate
 * Return: duplicated string
 */
char *_strdup(char *str)
{
	char *duplicate;

	if (str == NULL)
	{
		return (NULL);
	}

	duplicate = malloc(_strlen(str));
	if (duplicate == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	_strcpy(duplicate, str);

	return (duplicate);
}
/**
 * _igetline - custom getline function that reads a line from stdin
 * @lineptr: pointer to string where line will be stored
 * @n: number of characters
 * @stream: file from which the line will be read
 *
 * Return: line read from stdin
 */
ssize_t _igetline(char **lineptr, size_t *n, FILE *stream);
ssize_t _igetline(char **lineptr, size_t *n, FILE *stream)
{
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}

	char *line = *lineptr;
	size_t len = *n;
	ssize_t read_track = 0;
	ssize_t read_result;
	char current;

	if (line == NULL || len == 0)
	{
		len = BUFFER_SIZE;
		line = (char *) malloc(len);
		if (line == NULL)
		{
			return (-1);
		}
	}
	while (1)
	{
		read_result = read(fileno(stream), &line[read_track], 1);

		if (read_result <= 0)
		{
			if (read_track == 0)
			{
				free(line);
				*lineptr = NULL;
				return (-1);
			}
			break;
		}
		if (read_track + 1 >= len)
		{
			len *= 2;
			char *new_line = realloc(line, len);

			if (new_line == NULL)
			{
				free(line);
				*lineptr = NULL;
				return (-1);
			}
			line = new_line;
		}

		line[read_track++] = current;

		if (current == '\n')
		{
			line[read_track] = '\0';
			*lineptr = line;
			*n = len;
			return (read_track);
		}
	}

	return (-1);
}
