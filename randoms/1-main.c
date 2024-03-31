#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
*  * main - Entry point
*   *
*    * Return: 0 on success, error code otherwise
*     */
int main(void)
{
int len, len2;

printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
_printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
_printf("A char inside a sentence: %c. Did it work?\n", 'F');
len = _printf("Let's print a simple sentence.\n");
len2 = printf("Let's print a simple sentence.\n");
fflush(stdout);
if (len != len2)
{
printf("Lengths differ.\n");
fflush(stdout);
return (1);
}
return (0);
}
