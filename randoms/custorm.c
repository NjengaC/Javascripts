#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int _putchar(char c)
{
    return write(1, &c, 1);
}

void print_number(int n)
{
    if (n < 0)
    {
        _putchar('-');
        n = -n;
    }

    if (n >= 10)
    {
        print_number(n / 10);
    }

    _putchar('0' + (n % 10));
}

void handle_c(va_list args, int *buffer_index, char buffer[], int *printed_chars)
{
    buffer[(*buffer_index)++] = va_arg(args, int);
    (*printed_chars)++;
}

void handle_s(va_list args, int *buffer_index, char buffer[], int *printed_chars)
{
    char *str = va_arg(args, char *);
    while (*str)
    {
        buffer[(*buffer_index)++] = *str++;
        (*printed_chars)++;
    }
}

void handle_d_i(va_list args, int *buffer_index, char buffer[], int *printed_chars)
{
   int num = va_arg(args, int);
	int num_chars = 0;
   print_number(num);
   (*printed_chars) += num_chars;
}

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char buffer[BUFFER_SIZE];
    int buffer_index = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    handle_c(args, &buffer_index, buffer, &printed_chars);
                    break;
                case 's':
                    handle_s(args, &buffer_index, buffer, &printed_chars);
                    break;
                case 'd':
                case 'i':
                    handle_d_i(args, &buffer_index, buffer, &printed_chars);
                    break;
                case '%':
                    buffer[buffer_index++] = '%';
                    printed_chars++;
                    break;
                default:
                    buffer[buffer_index++] = '%';
                    buffer[buffer_index++] = *format;
                    printed_chars += 2;
                    break;
            }
        }
        else
        {
            buffer[buffer_index++] = *format;
            printed_chars++;
        }

        if (buffer_index >= BUFFER_SIZE - 1)
        {
            buffer[buffer_index] = '\0';
            write(1, buffer, buffer_index);
            buffer_index = 0;
        }

        format++;
    }

    va_end(args);

    if (buffer_index > 0)
    {
        buffer[buffer_index] = '\0';
        write(1, buffer, buffer_index);
    }

    return printed_chars;
}

