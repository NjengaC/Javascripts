#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *memalloc(char *str);
char *memalloc(char *str)
{
	char *random = NULL;

	random = strdup(str);

	printf("%ld\n%ld\n", strlen(str), strlen(random));

	return (random);
}

int main()
{
	char *str = "Heloo";
	char *copy;

	copy = memalloc(str);

	printf("%s\n", str);
	free(copy);
}
