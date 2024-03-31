#include "shell.h"
/**
 * reset - resets variables and returns wait status
 * @argv: commandline args and their flags
 * @command: specific commands as taken by getline
 * @token: string variable to create tokens using strtok
 * @count: track to the arguments
 *
 * Return: status of the child process
 */
int reset(char ***argv, char **command, char **token, int *count)

{
	int i = 0;

	while (argv[i] != NULL)
	{
		(argv[i]) = NULL;
		i++;
	}
	*argv = NULL;
	*command = NULL;
	*token = NULL;
	*count = 0;

	return (0);
}
/**
 * _strtok - breaks string into an array of null-terminated strings(tokena)
 * @input: a string (command arguments)
 * Return: an array on null-terminated strings
 */

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
	return (tokens);
}
/**
 * get_exe - gets the full PATH for specified executable
 * @command: command for whose exe we are getting
 * Return: returns the full path
 */
char *get_exe(char *command)
{
	char path[] = SHELL_PATH;
	char *token;
	char *full_path;

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		else
			return (NULL);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(1);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strncat(full_path, command, strlen(command) + 1);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(full_path);
	return (NULL);
}
/**
 * check_inbuilts - checks and handles inbuilt command arguments
 * @input: string to check
 * Return: 1 if one exists or 0 if none
 */
int check_inbuilts(char *input)
{
	if (_strcmp(input, "exit") == 0 || _strcmp(input, "setenv") == 0)
	{
		return (1);
	}
	else if (_strcmp(input, "unsetenv") == 0 || _strcmp(input, "cd") == 0)
	{
		return (1);
	}
return (0);

}
/**
 * main - entry point for the command line interpreter, displays a prompt
 * and waits for the user to type a command
 * Return: 0 On success
 */
int main(void);
int main(void)
{
	char *command = NULL;
	int status, count = 0;
	char *token = NULL, *full_path = NULL;
	char **av = NULL;
	ssize_t read;
	size_t len = 0;

	while (1)
	{
		printf("$ ");
		read = getline(&command, &len, stdin);
		if (read == -1 || _strcmp(command, "exit") == 0 || feof(stdin))
		{
			printf("\n");
			break;
		}
		else
		{
			av = _strtok(command);
			printf("command:%s\n", command);
			printf("%s, %s\n", av[0], av[1]);
			if ((check_inbuilts(av[0])) == 1)
				handle_builtins(av);
			else
			{
				av[0] = get_exe(av[0]);
				printf("fullpath:%s\n", av[0]);
				pid_t child_pid = fork();

				if (child_pid == 0)
				{
					execve(av[0], av, environ);
					printf("We reached here");
				}
				else
				{
					reset(&av, &command, &token, &count);
					wait(&status);
					if (status != 0)
						perror("command no found");
				}
			}
		}
	}
	free_sarray(av);
	free_str(full_path);
	free_str(command);
	return (0);
}
