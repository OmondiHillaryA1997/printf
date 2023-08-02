#include "main.h"


/***********GET WIDTH LENGTH**********/

/**
 * g_width - gets lenth width to be printed
 * @format: formatted string
 * @i: argument list to be printed
 * @lst_prnt: argument list
 *
 * Return: width length
 */

int g_width(const char *format, int *i, va_list lst_prnt)
{
	int c_r_index, width = 0;

	for (c_r_index = *i + 1; format[c_r_index] != '\0'; c_r_index++)
	{
		if (i_digit(format[c_r_index]))
		{
			width *= 10;
			width += format[c_r_index] - '0';
		}
		else if(format[c_r_index] == '*')
		{
			c_r_index++;
			width = va_arg(lst_prnt, int);
			break;
		}
		else
			break;
	}
	*i = c_r_index - 1;

	return (width);
}
