#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>
/*
int _strtok(char *str, const char delim)
{
	int i = 0,j = 0;
	char arr[15];

	while (str)
	{
		if (str[i] != delim)
		{
			arr[j] = str[i];
			i++;
		}
		else
		{
			arr[i] = '\0';
			i++;
			printf("%s\n", arr);

			arr = NULL;
			j = 0;
			continue;
		}
	}
	return (0);
}
*/
int main()
{
	char string[] = "Hello,World,!";
	char *token;
	char delim[] = ",";

	token = strtok(string, ",");

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, ",");
	}
	return (0);
}
