#include "shell.h"


char **_strtok(char *input)
{
        char **tokens = malloc(strlen(input) * sizeof(char *));

        if (tokens == NULL)
        {
                perror("malloc");
                exit(1);
        }

        char *token = NULL;
        int token_count = 0;

        token = strtok(input, " \t\n");
        while (token != NULL)
        {
                tokens[token_count] = strdup(token);
                if (tokens[token_count] == NULL)
                {
                        perror("strdup");
                        exit(1);
                }
                token_count++;
                token = strtok(NULL, " \t\n");
        }

        tokens[token_count] = NULL;
        free_str(token);
        return (tokens);
}

int main()
{
	char *command = NULL;
	ssize_t len = 0;

	getline(&command, &len, stdin);
	char **arr = _strtok(command);

	free_sarray(arr);
	free(command);

	return (0);
}

