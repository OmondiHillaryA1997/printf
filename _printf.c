#include "main.h"

void prnt_buff(char buf[], int *b_end);

/**
 * printf - Function to print printf emulator
 * @format: character string
 *
 * Return: integer
 */

int _printf(const char *format, ...)
{
	/* Initialization of integers */
	int i, count = 0, count_ch = 0;

	/* Declaration of helper functions */
	int flags, width, precision, size, b_end;

	/* optional arguments */
	va_list lst_prnt;
	char buf[PRINTF_BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lst_prnt, format); /* optional argument Declaration */
	for(i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buf[b_end++] = format[i];
			if (b_end == PRINTF_BUFF_SIZE)
				prnt_buff(buf, &b_end);
count_ch++;
		}
		else
		{
			prnt_buff(buf, &b_end);
			flags = find_flgs(format, &i);
			width = g_width(format, &i, lst_prnt);
			precision = g_precision(format, &i, lst_prnt);
			size = g_size(format, &i, lst_prnt);
			i++;
			count = specifier_prnt(format, &i, lst_prnt, buf, flags, width, precision, size);

			if (count == -1)
				return (-1);
			count_ch = count + 1;
		}
	}

	prnt_buff(buf, &b_end);

	va_end(lst_prnt);

	return (count_ch);
}

/**
 * prnt_buff - Function that prints content of the buffer
 * @buf: character array
 * @b_end: legnth index
 *
 */

void prnt_buff(char buf[], int *b_end)
{
	if (*b_end > 0)
		write(1, &buf[0], *b_end);
	*b_end = 0;
}
