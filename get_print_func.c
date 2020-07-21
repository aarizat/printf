#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"
/**
 * _printf - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int (*f_prnt)(va_list);
	int i = 0, j, count = 0, c = 0;
	ft a[] = {{'c', print_char}, {'s', print_str}, {'d', print_int},
		  {'i', print_int}, {'b', print_bin}, {'u', print_ui},
		  {'o', print_oct}, {'x', print_hex}, {'X', print_HEX},
		  {'\0', NULL},
	};

	if (format == NULL || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			for (j = 0; j < 9; j++)
			{
				if (format[i] == a[j].id)
				{
					f_prnt = a[j].fp;
					c = f_prnt(args);
					count = count + c;
					break;
				}
			}
			if (j == 9)
			{
				c = print_spe(format[i]);
				count = count + c;
			}
		}
		i++;
	}
	va_end(args);
	return (count);
}
