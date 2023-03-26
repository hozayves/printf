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
 * Return: nothing
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
	/* va_list args_copy; */

	for (i = 0; i < 9 && *valid_specs[i].spec != *format; i++)
	{
		j++;
	}

	if (j < 9)
	{
		local_printed = valid_specs[j].func(args);
	}
	else
	{
		return (0);
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

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			char_printed++;
		}
		else
		{
			format++;
			char_printed += _handle_print(format, args);
		}
		format++;
	}
	va_end(args);
	return (char_printed);
}
