#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
*  * main - Entry point
*   *
*    * Return: Always 0
*     */
int main(void)
{
int len;
int len2;
unsigned int ui;
void *addr;
char *str = "Let's try to printf aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa simple sentence.\n";
len = _printf("Let's try to printf a simple sentence.\n");
len2 = printf("Let's try to printf a simple sentence.\n");
ui = (unsigned int)INT_MAX + 1024;
addr = (void *)0x7ffe637541f0;
_printf("Length:[%d, %i]\n", len, len);
printf("Length:[%d, %i]\n", len2, len2);
_printf("Negative:[%d]\n", 12);
_printf("Negative:[%d]\n", 762537346);
printf("Negative:[%d]\n", 762537346);
_printf("Unsigned:[%u]\n", ui);
printf("Unsigned:[%u]\n", ui);
_printf("Unsigned octal:[%o]\n", ui);
printf("Unsigned octal:[%o]\n", ui);
_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
_printf("Character:[%c]\n", 'H');
printf("Character:[%c]\n", 'H');
_printf("String:[%s]\n", "I am a string !");
printf("String:[%s]\n", "I am a string !");
_printf("Address:[%p]\n", addr);
printf("Address:[%p]\n", addr);
len = printf("Percent:[%%]\n");
len2 = printf("Percent:[%%]\n");
_printf("Len:[%d]\n", len);
printf("Len:[%d]\n", len2);
_printf("Unknown:[%r]\n");
printf("Unknown:[%r]\n");
_printf("%K\n");
_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
_printf("man gcc:\n%s", str);
printf(NULL);
_printf("%\n");
_printf("%!\n");
printf("%c\n", '\0');
_printf("%");
_printf("%b\n", 98);
_printf("%b\n", 0);
_printf("%b\n", UINT_MAX);
_printf("There is %b bytes in %b KB\n", 1024, 1);
return (0);
}
