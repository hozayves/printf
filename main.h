#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>

/* Functions for specifiers */
int _print_char(va_list args);
int _print_str(va_list args);
int _print_int(va_list args);

/**
 * struct specifiers - link a specifer to
 * his corresponding function
 *
 * @spec: the format specifier
 * @func: the corresponding function
 */
typedef struct specifiers
{
	char *spec;
	int (*func)(va_list args);
} _spec_dt;

int _putchar(char c);

/* Functions selector */
int _handle_print(const char *format, va_list args);

/* main _printf function */
int _printf(const char *format, ...);

/* End of _PRINTF_H */
#endif
