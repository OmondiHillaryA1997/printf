#include "main.h"

/**************GET PRECISION********/

/**
 * g_precision - get precision
 * @format: formatted string
 * @i: argument list to be printed
 * @lst_prnt: arguments list
 *
 * Return: precision
 */

int g_precision(const char *format, int *i, va_list lst_prnt)
{
	int c_r_index = *i + 1;
	int precision = -1;

	if (format[c_r_index] != '.')
		return (precision);

	precision = 0;

	for (c_r_index += 1; format[c_r_index] != '\0'; c_r_index++)
	{
		if (i_digit(format[c_r_index]))
		{
			c_r_index++;
			precision = va_arg(lst_prnt, int);
			break;
		}
		else
			break;
	}
	*i = c_r_index - 1;

	return (precision);
}
