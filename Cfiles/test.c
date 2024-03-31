nt u_hexadeci(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";

if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}int u_hexadeci(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";

if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}int u_hexadeci(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";

if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}int u_hexadeci(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";

if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}int u_hexadeci(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";

if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (3);
}#include "main.h"

int main()
{
	int a = 40;
	char *s = "Unknown";

	_printf("%d\n", a);
	_printf(":[%m]\n");
	_printf("Unknown:[%r]\n");
	_printf("%R\n", s);
}
