#include <stdlib.h>
#include "main.h"
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0,k = 0, m = 0, n = 0;
	char *new;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[i] != '\0')
		i++;

	while (s2[j] != '\0')
		j++;

	new = malloc((j + i + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);

	while (s1[m] != '\0')
	{
		new[k] =s1[m];
		m++;
		k++;
	}
	while (s2[n] != '\0')
	{
		new[k] = s2[n];
		n++;
		k++;
	}
	new[k] = '\0';
return (new);
}
