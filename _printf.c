#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - a function that produces output according to a format
 * @format: a character string
 *
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *str;
    char c;

    if (!format)
        return (0); /* NULL olsa 0 qaytarır */

    va_start(args, format);

    /* for dövrü ilə hər simvolu oxuyuruq */
    for (; *format != '\0'; format++)
    {
        if (*format == '%')
        {
            format++; /* növbəti simvol format tipidir */

            if (*format == 'c') /* char */
            {
                c = (char) va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == 's') /* string */
            {
                str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                for (; *str != '\0'; str++)
                {
                    write(1, str, 1);
                    count++;
                }
            }
            else if (*format == '%') /* procent */
            {
                write(1, "%", 1);
                count++;
            }
            else /* unknown format */
            {
                write(1, "%", 1);
                write(1, format, 1);
                count += 2;
            }
        }
        else /* normal simvol */
        {
            write(1, format, 1);
            count++;
        }
    }

    va_end(args);
    return (count);
}
