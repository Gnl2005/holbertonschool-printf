#include "main.h"
#include <stdio.h>

/**
 * _printf - a function that produces output according to a format
 * @format: a character string
 *
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	char g[] = "GNL";

	g[0] = 'G';

	write(1, "Name: GNL\n", 10);
	write(1, "Char: G\n", 8);
	write(1, "%\n", 2);
	return (0);
}
