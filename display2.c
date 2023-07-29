#include "main.h"


/*********DISPLAY REVERSE*********/
/**
 * display_reverse - Function that displays reverse string
 * @clas: arguments list
 * @buf:array buffer
 * @flags: get flags
 * @width: get length width
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: integer
 */

int display_reverse(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	char *s;
	int index, cnt;

	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(clas, char *);

		if (s == NULL)
		{
			UNUSED(precision);

			s = ")Null(";
		}
	index = 0;
	for (; s[index]; index++)
		;

	for (index = index - 1; index >= 0; index--)
	{
		char p = s[index];

		write(1, &p, 1);
		cnt++;
	}
	return (cnt);
}

/***********DISPLAY POINTER*******/

/**
 * display_pointer - Function that displays pointer datatype
 * @clas: arguments lists
 * @buf: array buffer
 * @width: get length width
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: integer
 */

int display_pointer(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	char exc = 0, pad = ' ';
	int in_d = PRINTF_BUFF_SIZE - 2, length = 2, pad_start = 1;
	unsigned long nm_adrs;
	char hold[] = "0123456789abcdef";
	void *adrs = va_arg(clas, void *);

	UNUSED(width);
	UNUSED(size);

	if (adrs == NULL)
		return (write(1, "(nil)", 5));

	buf[PRINTF_BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	nm_adrs = (unsigned long)adrs;

	while (nm_adrs > 0)
	{
		buf[in_d--] = hold[nm_adrs % 16];
		nm_adrs /= 16;
		length++;
	}

	if((flags & fl_ziro) && !(flags & fl_minas))
		pad = '0';
	if(flags & fl_plas)
		exc = '+', length++;
	else if (flags & fl_spes)
		exc = ' ',length++;

	in_d++;

	return (display_pointer(buf, in_d, length, width, flags, pad, exc, pad_start));
}


/***********DISPLAY STRING ROT13**********/

/**
 * display_rot13s - displays ROT13 string
 * @clas: arguments list
 * @buf: array buffer
 * @flags: counts flags
 * @width: get length width
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: integer
 */

int display_rot13s(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	char x;
	char *s;
	unsigned int index, g;
	int cnt;
	char i_n[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char o_t[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(clas, char *);
	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	index = 0;
	for (; s[index]; index++)
	{
		g = 0;
		for (; i_n[g]; g++)
		{
			if (i_n[g] == s[index])
			{
				x = o_t[g];
				write(1, &x, 1);
				cnt++;
				break;
			}
		}
		if (!i_n[g])
		{
			x = s[index];
			write(1, &x, 1);
			cnt++;
		}
	}
	return (cnt);
}


/********DISPLAY NON_PRINTABLE*****/

/**
 * display_n_printable - displays non printable ascii char in hexadecimal
 * @clas: arguments list
 * @buf: array buffer
 * @flags: counts flags
 * @width: get width length
 * @precison: specifies precision
 * @size: specifies size
 *
 * Return: integer
 */

int display_n_printable(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	int index, o_st;
	char *s = va_arg(clas, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	o_st = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (is_print(s[index]))
			buf[index + o_st] = s[index];
		else
			o_st += ap_hx_cd(s[index], buf, index + o_st);
		index++;
	}
	buf[index + o_st] = '\0';

	return (write(1, buf, index + o_st));
}

/***********GET WIDTH LENGTH**********/

/**
 * g_width - gets lenth width to be printed
 * @format: formatted string
 * @index: argument list to be printed
 * @lst_prnt: argument list
 *
 * Return: width length
 */

int g_width(const char *format, int *index, va_list lst_prnt)
{
	int c_r_index, width = 0;

	for (c_r_index = *index + 1; format[c_r_index] != '\0'; c_r_index++)
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
	*index = c_r_index - 1;

	return (width);
}

/**********GET SIZE*********/

/**
 * g_size - gets size
 * @format: formatted string
 * @index: argument lidt
 *
 * size
 */

int g_size(const char *format, int *index)
{
	int c_r_index = *index + 1;
	int size = 0;

	if (format[c_r_index] == 'i')
		size = SIZE_LONG;
	else if (format[c_r_index] == 'h')
		size = SIZE_SHORT;

	if (size == 0)
		*index = c_r_index - 1;
	else
		*index = c_r_index;

	return (size);
}
