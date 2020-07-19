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
		  {'i', print_int}, {'\0', NULL},
	};
	va_start(args, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				_putchar(format[i]);
				count++;
			}
			else
			{
				for (j = 0; j < 4; j++)
				{
					if (format[i] == a[j].id)
					{
						f_prnt = a[j].fp;
						c = f_prnt(args);
						count = count + c;
						break;
					}
				}
				if (j == 4 && format[i] == 'r')
				{
					_putchar(format[i - 1]);
					count++;
					_putchar(format[i]);
					count++;
				}
				else if (j == 4)
				{
					_putchar(format[i - 1]);
					count++;
				}
			}
		}
		i++;
	}
	return (count);
}
