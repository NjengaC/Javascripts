#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
int status;
char *argv[] = {"ls", "ls", "-l", "/tmp", NULL};

for (int i = 0; i < 4; i++)
{
pid_t child_pid = fork();

if (child_pid == -1)
{
perror("fork");
return 1;
}

if (child_pid == 0)
{
execve(argv[0], argv, NULL);
perror("execve");
_exit(1);
}
else
{
wait(&status);
}
}
return 0;
}
