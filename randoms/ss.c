#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
/*
char *custom_getline()
{
static char buffer[BUFFER_SIZE]; 
static size_t position = 0;
static size_t bytesRead = 0; 
char *line = NULL;
size_t lineLength = 0;
ssize_t bytesReadThisTime = 0;

if (position >= bytesRead)
{
bytesReadThisTime = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (bytesReadThisTime <= 0) {
return NULL;
}
bytesRead = (size_t)bytesReadThisTime;
position = 0;
}


while (position < bytesRead) {
char currentChar = buffer[position++];
if (currentChar == '\n') {
break; 
}
line = realloc(line, lineLength + 2); 
if (line == NULL) {
perror("realloc");
exit(EXIT_FAILURE);
}
line[lineLength++] = currentChar;
}

if (line != NULL) {
line[lineLength] = '\0';
}

return line;
}
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
if (lineptr == NULL || n == NULL || stream == NULL)
{
return (-1);
}

char *line = *lineptr;
size_t len = *n;
ssize_t read_track = 0;

if (line == NULL || len == 0)
{
len = BUFFER_SIZE;
line = malloc(len);
if (line == NULL)
{
return (-1);
}
}

while (1)
{
if (len - read_track < 2)
{
len *= 2;
char *new_line = realloc(line, len);

if (new_line == NULL)
{
return (-1);
}
line = new_line;
}

char current;
ssize_t read_result = read(fileno(stream), &current, 1);

if (read_result <= 0)
{
if (read_track == 0)
{
free(line);
*lineptr = NULL;
return (-1);
}
break;
}

line[read_track++] = current;

if (current == '\n')
{
line[read_track] = '\0';
*lineptr = line;
*n = len;
return (read_track);
}
}

return (-1);
}
int main() {
	    char *line = NULL;
	        size_t len = 0;
		    ssize_t read_result;

		    printf("Entry$ ");

		        while ((read_result = _getline(&line, &len, stdin)) != -1) {
				        printf("Line read from stdin: %s", line);
					    }

			    if (line != NULL) {
				            free(line);
					        }

			        return 0;
}
