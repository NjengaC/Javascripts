#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings
 * @s1: destination string
 * @s2: source string
 * @n: first bytes of s2
 *
 * Return: pointer to newly allocated space in mem.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int l = 0;
	unsigned int x = 0;
	char *new;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (!s1[i] == '\0')
		i++;

	while (!s2[j] == '\0')
		j++;

	if (j < n)
		new = malloc(sizeof(char) * (i + j + 1));
	else
		new = malloc(sizeof(char) * (i + n + 1));

	if (new == NULL)
		return (NULL);
	for (; l < i; l++)
	{
		new[l] = s1[l];
	}
	while (j > n && x < n)
		{
		new[l++] = s2[x++];
		}
	while (j < n && x < j)
		{
		new[l++] = s2[x++];
		}
	new[l] = '\0';
	return (new);
}
