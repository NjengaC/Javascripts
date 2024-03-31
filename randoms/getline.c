#include "shell.h"
/**
 * hash - Function that handles the case where # has been used in a command.
 * @buffer: The pointer to where the user input is stored.
 *
 * Return: buffer after the #has been ignored hence a comment.
 
char *_getline()
{
	char *buf, r = 0;
	int i = 0, chars_read, buf_size;

	buf_size = BUFFER_SIZE,	buf = malloc(buf_size * sizeof(char));

	if (buf == NULL)
	{
		free(buf);
		return (NULL);
	}

	while (r != EOF && r != '\n')
	{
		fflush(stdin);
		chars_read = read(STDIN_FILENO, &r, 1);
		if (chars_read == 0)
		{
			free(buf);
			exit(EXIT_SUCCESS);
		}
		buf[i] = r;
		if (buf[0] == '\n')
		{
			free(buf);
			return ("\0");
		}

		i++;
	}
	buf[i] = '\0', buf = handle_hash(buf);
	if (buf == NULL)
	{
		return ("\0");
	}
	return (buf);
}

**
 * handle_hash - Handles # in commandline args
 * @buf: pointer to storage point
 *
 * Return: buf
 *

char *handle_hash(char *buf)
{
	int i;
	bool state = false;

	if (buf[0] == '#')
	{
		free(buf);
		return (NULL);
	}

	else
	{
		for (i = 0; buf[i]; i++)
		{
			if (buf[i] == 34)
			{
				state = !state;
			}

			if (!state && buf[i] == '#' && buf[i - 1] == ' ')
			{
				buf[i] = '\0';
				break;
			}
		}
	}

	return (buf);
}*/
/**
 * free_sarray - frees an array of strings
 * @av: the array to free
 * Return: 0 on success
 */
int free_sarray(char **av)
{
	if (av == NULL)
		return (0);
	int i = 0;

	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}

	free(av);
	
	return (1);
}

/**
 * free_str - frees a string
 * @str: a string allocated memory by malloc
 * Return: 0 on success
 */
int free_str(char *str)
{
	if (str == NULL)
		return (0);
	else
		free(str);

return (1);
}
