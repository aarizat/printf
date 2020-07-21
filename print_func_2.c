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
	}
	return (c);
}

/**
 * print_S - prints a string
 * @str: string to be printed
 *
 * Return: number of characters printed.
 */

int print_S(va_list str)
{
	int c = 0;
	char *nul = "(null)";
	char *s =  va_arg(str, char *);

	if (s == NULL || s == 0)
	{
		while (*nul)
		{
			c += _putchar(*nul);
			nul++;
		}
	}
	else
	{
		while (*s)
		{
			if ((*s > 0 && *s <= 15))
			{
				_putchar('\\');
				c++;
				_putchar('x');
				c++;
				_putchar('0');
				c++;
				c = c + conv_HEX(*s);
			}
			else if ((*s > 15 && *s < 32) || *s >= 127)
			{
				_putchar('\\');
				c++;
				_putchar('x');
				c++;
				c = c + conv_HEX(*s);
			}
			else
				c += _putchar(*s);
			s++;
		}
	}
	return (c);
}
/**
 * conv_HEX - Converts to HEXA
 * @n: Char to convert
 *
 * Return: number of characters printed.
 */
int conv_HEX(char n)
{
	int num = n;
	int i, j, c = 1;
	int arr[10];

	arr[0] = num % 16;
	for (i = num / 16; i; i = i / 16)
	{
		arr[c] = i % 16;
		c++;
	}
	for (j = c - 1; j >= 0; j--)
	{
		if (arr[j] > 9)
		{
			arr[j] = arr[j] + 7;
		}
		_putchar('0' + arr[j]);
	}
	return (c);
}

/**
 * print_p - print the address memory from a pointer.
 * @pointer: pointer.
 *
 * Return: number of printed characters
 */

int print_p(va_list pointer)
{
	unsigned long int p = va_arg(pointer, unsigned long int);
	unsigned long int i;
	int j, c = 1;
	int  arr[1000];
	char *nil = "(nil)";

	if (p == 0)
	{
		c = 0;
		while (*nil)
		{
			c += _putchar(*nil);
			nil++;
		}
	}
	else
	{
		_putchar(48);
		_putchar(120);
		arr[0] = p % 16;
		for (i = p / 16; i; i = i / 16)
		{
			arr[c] = i % 16;
			c++;
		}
		for (j = c - 1; j >= 0; j--)
		{
			if (arr[j] > 9)
			{
				arr[j] = arr[j] + 39;
			}
			_putchar('0' + arr[j]);
		}
		c += 2;
	}
	return (c);
}
