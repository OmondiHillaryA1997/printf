/************HANDLES ARGUMENTS DEPENDING ON DATATYPE************/


#include "main.h"

/**
 * specifier_print - function that printd an argument depending on type
 * @spec: formatted string that prints arguments
 * @lst_prnt: argument list to be printed
 * @in_d: ind.
 * @buf: array buffer
 * @flags: counts flags
 * @width: get width length
 * @precision: specifies precision
 * @size: specifies aize
 *
 * Return: 1 or 2
 */

int specifier_print(const char *spec, int *in_d, va_list lst_prnt, char buf[], int flags, int width, int precision, int size)
{
	int i, un_len = 0, counts_ch = -1;
	spec_t spec_clas[] = {
		{'c', display_char}, {'s', display_str}, {'%', display_percent},
		{'i', display_integer}, {'d', display_integer}, {'b', display_binary},
	       {'u', display_unsigned_integer}, {'o', display_unsg_octal}, {'x', display_hexadecimal},
	       {'X', display_unsgn_upprhex}, {'p', display_pointer}, {'S', display_n_printable },
	       {'r', display_reverse}, {'R', display_rot13s}, {'\0', NULL}
	};

	i = 0;
	for (; spec_clas[i].spec != '\0'; i++)
		if (spec[*in_d] == spec_clas[i].spec)
			return (spec_clas[i].fn(lst_prnt, buf, flags, width, precision, size));

	if (spec_clas[i].spec == '\0')
	{
		if (spec[*in_d] == '\0')
			return(-1);

		un_len += write(1, "%%", 1);
		if (spec[*in_d - 1] == ' ')
			un_len += write(1, "", 1);
		else if (width)
		{
			--(*in_d);
			while (spec[*in_d] != ' ' && spec[*in_d] != '%')

				--(*in_d);
			if (spec[*in_d] == ' ')
				--(*in_d);
			return (1);
		}
		un_len += write(1, &spec[*in_d], 1);
			return (un_len);
	}
	return (counts_ch);
}
