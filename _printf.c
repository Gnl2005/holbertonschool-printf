#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints a single character
 * @c: character to print
 *
 * Return: 1
 */
int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @str: string to print
 *
 * Return: number of chars printed
 */
int print_string(char *str)
{
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}

	return (count);
}

/**
 * _printf - prints formatted output
 * @format: format string
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (0);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += print_char((char)va_arg(args, int));
			else if (*format == 's')
				count += print_string(va_arg(args, char *));
			else if (*format == '%')
				count += print_char('%');
			else
			{
				count += print_char('%');
				count += print_char(*format);
			}
		}
		else
			count += print_char(*format);
		format++;
	}

	va_end(args);
	return (count);
}
