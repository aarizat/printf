#include <stdarg.h>
#include "holberton.h"
#include <stdio.h>
/**
 * print_ui - print an undigned int.
 * @ui: number to print.
 *
 * Return: nothing.
 */

int print_ui(va_list ui)
{
	int len, i, n, count = 0;

	n = va_arg(ui, unsigned int);
	i = 1;
	len = 1;
	if (n / (1000000000) != 0)
		len = 1000000000;
	else
	{
		while (n / i != 0)
		{
			len = i;
			i = i * 10;
		}
	}
	while (len > 0)
	{
		_putchar('0' + (n / len));
		count++;
		n = n % len;
		len = len / 10;
	}
	return (count);
}
