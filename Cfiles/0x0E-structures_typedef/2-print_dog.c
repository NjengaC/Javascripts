#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
/**
 * print_dog - prints a struct dog to std out
 * @d: pointer tp struct dog
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;
	if (d->name == NULL)
		d->name = "(nil)";
	if (d->owner == NULL)
		d->owner = "(nil)";
	printf("Name: %s\nAge: %.6f\nOwner: %s\n", d->name, d->age, d->owner);
}
