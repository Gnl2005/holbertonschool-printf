#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct spec - formata uyğun funksiya saxlamaq üçün struktur
 * @specifier: format simvolu (məs: "c", "s", "d", "i", "%")
 * @func: həmin formatı çap edən funksiya pointeri
 */
typedef struct spec
{
	char *specifier;
	int (*func)(va_list args, int length);
} spec;

/* Function prototypes */
int _printf(const char *format, ...);

int print_char(va_list args, int length);
int print_string(va_list args, int length);
int handle_mod(va_list args, int length);
int print_int(va_list args, int length);

#endif /* MAIN_H */
