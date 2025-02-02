#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define SHELL_PATH "/bin:/usr/bin"
extern char **environ;

int reset(char ***argv, char **command, char **token, int *count);
char *get_exe(char *command);
char *c_strtok(char *strn, const char *delimiter);
int handle_builtins(char **av);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strchr(char *s, char c);
int _putchar(char c);
int _atoi(char *s);
char *_strdup(char *str);
ssize_t _igetline(char **lineptr, size_t *n, FILE *stream);
char **_strtok(char *input);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int _chdir(char **av);
char *_getline();
char *handle_hash(char *buf);
int free_str(char *str);
int free_sarray(char **av);
#endif
