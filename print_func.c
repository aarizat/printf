#include <stdarg.h>
#include "holberton.h"
#include <stdio.h>

/**
 * print_char - print a character.
 * @ch: character to print.
 *
 * Return: nothing.
 */

int print_char(va_list ch)
{
	int c = 0;

	_putchar(va_arg(ch, int));
	c++;
	return (c);
}

/**
 * print_str - print a character array.
 * @str: string to print.
 *
 * Return: nothing.
 */

int print_str(va_list str)
{
	int c = 0;
	char *nul = "(null)";
	char *s =  va_arg(str, char *);

	if (s == NULL || s == 0)
	{
		while (*nul)
		{
			_putchar(*nul);
			nul++;
			c++;
		}
	}
	else
	{
		while (*s)
		{
			_putchar(*s);
			c++;
			s++;
		}
	}
	return (c);
}

/**
 * print_int - print an integer.
 * @integer: integer number to print.
 *
 * Return: nothing.
 */

int print_int(va_list integer)
{
	int len, i, n, count = 0;

	n = va_arg(integer, int);
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
	if (n < 0)
	{
		_putchar('-');
		count++;
		while (len > 0)
		{
			_putchar('0' + ((n / len) * -1));
			count++;
			n = n % len;
			len = len / 10;
		}
	}
	else
	{
		while (len > 0)
		{
			_putchar('0' + (n / len));
			count++;
			n = n % len;
			len = len / 10;
		}
	}
	return (count);
}

/**
 * print_spe - print an integer.
 * @c: character to print.
 *
 * Return: nothing.
 */

int print_spe(char c)
{
	int count = 0;

	if (c == '%')
	{
		_putchar('%');
		count++;
	}
	else
	{
		_putchar('%');
		count++;
		_putchar(c);
		count++;
	}
	return (count);
}

/**
 * print_bin - print from decimal to binary.
 * @n: number to convert to binary.
 *
 * Return: number of bytes printed.
 */

int print_bin(va_list n)
{
	unsigned int num = va_arg(n, unsigned int);
	int i, j, c = 1;
	int arr[9];

	arr[0] = num % 2;
	for (i = num / 2; i; i = i / 2)
	{
		arr[c] = i % 2;
		c++;
	}
	for (j = c - 1; j >= 0; j--)
		_putchar('0' +  arr[j]);
	return (c);
}
