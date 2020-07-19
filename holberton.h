#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdarg.h>

/**
 * struct identifier- struct to define a identifier format object.
 *
 * @id: identifier of function to call
 * @fp: The function associated
 */
typedef struct identifier
{
	char id;
	int (*fp)(va_list);
} ft;

int _putchar(char c);
int print_char(va_list ch);
int print_str(va_list str);
int print_int(va_list integer);
int _printf(const char *format, ...);
#endif /*_HOLBERTON_H*/
