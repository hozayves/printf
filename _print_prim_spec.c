#include <stdarg.h>
#include <stdlib.h>
#include "main.h"


/**
 * _print_char - prints a character to the
 * stdout
 *
 * @args: the variadic argument holding the
 * character to be printed
 *
 * Return: always (1) as number of character
 * printed
 */
int _print_char(va_list args)
{
	_putchar((char)va_arg(args, int));
	return (1);
}


/**
 * _print_str - prints a string to the stdout
 *
 * @args: the variadic argument holding the
 * integer to be printed
 *
 * Return: the number of characters localy printed
 */
int _print_str(va_list args)
{
	int local_print = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}

	while (*str)
	{
		_putchar(*str);
		str++;
		local_print++;
	}

	return (local_print);
}

/**
 * _print_int_order - prints the integer in order
 *
 * @number: the positive integer to print
 *
 * Return: nothing
 */
void _print_int_order(unsigned int number)
{
	if (number > 9)
		_print_int_order(number / 10);
	_putchar(number % 10 + '0');
}

/**
 * _print_int - prints a negative of positive integer
 * to the stdout
 *
 * @args: the variadic argument holding the
 * intger to be printed
 *
 * Return: number of values localy printed
 */
int _print_int(va_list args)
{
	int local_print = 0, value = 0;
	int number = va_arg(args, int);

	if (number < 0)
	{
		_putchar('-');
		number *= (-1);
		local_print++;
	}

	value = number;

	while (value > 9)
	{
		value /= 10;
		local_print++;
	}

	_print_int_order(number);
	return (local_print);
}
