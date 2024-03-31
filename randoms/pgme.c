#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
int main()
{
char str[100];
ssize_t len;

while (1)
{
	printf("$ ");
	fflush(stdout);

	fgets(str, sizeof(str), stdin);

	len = strlen(str);

	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
	}

	printf("%s", str);

return (0);
}
