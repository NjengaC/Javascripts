#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **av = NULL;
    //char *const argv[] = {"cat", "file", NULL};
    //char *const envp[] = {NULL};
    printf("$ ");
    read = getline(&line, &len, stdin);
    if (line[read - 1] == '\n')
    {
	    line[read - 1] = '\0';
    }
    
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL)
    {
	    av = realloc(av, (i + 1) * sizeof(char *));
	    av[i] = strdup(token);
	    i++;
	    token = strtok(NULL, " ");
    }
    av = realloc(av, (i + 1) * sizeof(char *));
    av[i] = NULL;
	    
	    
    int j = execvp(av[0], av);
    if (j == -1)
    {
        perror("execvp");
        return 1;
    }

    // This code will not be reached if execve is successful
    printf("This line will not be executed.\n");

    return 0;
}

