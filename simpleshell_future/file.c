#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	ssize_t len = 0;
	char *input = NULL;
	char *command;
	getline(&command, &len, stdin);

	input = strtok(command, ";");

	while (input != NULL)
	{
		printf("%s\n", input);
		input = strtok(NULL, ";");
	}
	return (0);
}
