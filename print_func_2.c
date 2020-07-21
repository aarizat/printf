#include <stdarg.h>
#include "holberton.h"
#include <stdio.h>

/**
 * print_rev - prints the reversed string
 * @str: string to reverse
 *
 * Return: number of characters printed.
 */

int print_rev(va_list str)
{
	int c = 0, i, len;
	char *s =  va_arg(str, char *);

	i = 0;
	while (s[i] != '\0')
	{
		len = i + 1;
		i++;
	}
	while (len > 0)
	{
		_putchar(s[len - 1]);
		c++;
		len--;
	}
	return (c);
}