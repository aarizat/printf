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
	int len, i, count = 0;
	unsigned int n;

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

/**
 * print_oct - print from decimal to octal
 * @n: number to convert.
 *
 * Return: nothing.
 */

int print_oct(va_list n)
{
	unsigned int num = va_arg(n, unsigned int);
	int i, j, c = 1;
	int arr[1000];

	arr[0] = num % 8;
	for (i = num / 8; i; i = i / 8)
	{
		arr[c] = i % 8;
		c++;
	}
	for (j = c - 1; j >= 0; j--)
		_putchar('0' + arr[j]);
	return (c);
}
/**
 * print_hex - print from decimal to hexadecimal
 * @n: number to convert.
 *
 * Return: number of preintedd characters
 */
int print_hex(va_list n)
{
	unsigned int num = va_arg(n, unsigned int);
	int i, j, c = 1;
	int arr[1000];

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
			arr[j] = arr[j] + 39;
		}
		_putchar('0' + arr[j]);
	}
	return (c);
}

/**
 * print_HEX - print from decimal to hexadecimal
 * @n: number to convert.
 *
 * Return: number of preintedd characters
 */
int print_HEX(va_list n)
{
	unsigned int num = va_arg(n, unsigned int);
	int i, j, c = 1;
	int arr[1000];

	arr[0] = num % 16;
	for (i = num / 16; i; i = i / 16)
	{
		arr[c] = i % 16;
		c++;
	}
	for (j = c - 1; j >= 0; j--)
	{
		if (arr[j] > 9)
			arr[j] = arr[j] + 7;
		_putchar('0' + arr[j]);
	}
	return (c);
}

/**
 * print_rot13 - Encode a string using rot 13
 * @s: string to enconde
 *
 * Return: number of characters pinted.
 */

int print_rot13(va_list s)
{
	char *str = va_arg(s, char *);
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *nul = "(null)";
	int i = 0, j = 0, count = 0;

	if (str == NULL)
	{
		while (*nul)
		{	_putchar(*nul);
			count++;
			nul++;
		}
	}
	else
	{
		while (str[i] != '\0')
		{
			for (j = 0; j < 52; j++)
			{
				if (str[i] == input[j])
				{
					_putchar(output[j]);
					count++;
					break;
				}
			}
			i++;
		}
	}
	return (count);
}
