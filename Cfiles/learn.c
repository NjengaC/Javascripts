#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i, j;
	int Next;
	
	if (argc != 3)
	{
		printf("Error\n");
		return(0);
	}
	else
	{
	i = atoi(argv[1]);
	j = atoi(argv[2]);
	Next = i + j - i % j;
	printf("The next largest number of days is: %d\n", Next);
	}
	return(0);
}	
