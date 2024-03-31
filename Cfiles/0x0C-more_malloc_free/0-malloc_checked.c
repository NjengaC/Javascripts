#include "main.h"
#include <stdlib.h>
/**
 * malloc_checked - allocates memory using the malloc function
 * @b: size of memory to allocate
 *
 * Return: a pointer to newly allocated mem block and 98 if failed
 */

void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);

	return (ptr);
}
