#include <stdarg.h>
#include <stdlib.h>
#include "main.h"


/**
 * _handle_print - call the adequate function according
 * to the format specifier
 *
 * @format: the string to be printed
 * @args: list of variadic arguments
 *
 * Return: loca printed characters
 */
int _handle_print(const char *format, va_list args)
{
	int i, j = 0, local_printed = 0;
	_spec_dt valid_specs[] = {
		{"c", _print_char},
		{"s", _print_str},
		{"d", _print_int},
		{"i", _print_int}
	};

	for (i = 0; i < 4 && *format != *valid_specs[i].spec; i++)
		j++;

	if (j < 4)
	{
		local_printed = valid_specs[j].func(args);
	}
	else if (*format == '%')
	{
		_putchar('%');
		return (1);
	}
	else
	{
		_putchar('%');
		_putchar(*format);
		return (2);
	}

	return (local_printed);
}


/**
 * _printf - write a given string to the standard output
 *
 * @format: the string to be printed (including formats)
 * @...: variadic arguments (variables to replace
 * the specifier with)
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int char_printed = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			char_printed += _handle_print(format, args);
		}
		else
		{
			_putchar(*format);
			char_printed++;
		}
		format++;
	}
	va_end(args);
	return (char_printed);
}
