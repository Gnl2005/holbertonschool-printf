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
	const char *g = "GNL"
	
	g[0] = 'G';
	g[1] = 'N';
	g[2] = 'L';

	_printf("Name: %s\n", g);
	_printf("Char: %c\n", g[0],g[1],g[2]);
	_printf(%%\n);
	return (0);
}
