#include <stdlib.h>
#include "main.h"

char *_strdup(char *str)
{
	int i = 0, j = 0;
	char *new;

	while (str[i] != '\0')
	{
		i++;
	}

	new = malloc(i * sizeof(char));

	if (new == NULL)
		return (NULL);

	while (i)
	{
		new[j] = str[j];
		j++;
		i--;
	}
	new[j] = '\0';

return (new);
}
