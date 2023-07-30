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
	char *st;
	int i, cnt;

	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	st = va_arg(clas, char *);

		if (st == NULL)
		{
			UNUSED(precision);

			st = ")Null(";
		}
	i = 0;
	for (; st[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = st[i];

		write(1, &z, 1);
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
	int in_d = PRINTF_BUFF_SIZE - 2, length = 2, pads = 1;
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

	return (write_pointer(buf, in_d, length, width, flags, pad, exc, pads));
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
	char *st;
	unsigned int i, g;
	int cnt;
	char i_n[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char o_t[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	st = va_arg(clas, char *);
	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (st == NULL)
		st = "(AHYY)";
	i = 0;
	for (; st[i]; i++)
	{
		g = 0;
		for (; i_n[g]; g++)
		{
			if (i_n[g] == st[i])
			{
				x = o_t[g];
				write(1, &x, 1);
				cnt++;
				break;
			}
		}
		if (!i_n[g])
		{
			x = st[i];
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
	int i, o_st;
	char *st = va_arg(clas, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (st == NULL)
		return (write(1, "(null)", 6));

	o_st = 0;
	i = 0;
	while (st[i] != '\0')
	{
		if (is_print(st[i]))
			buf[i + o_st] = st[i];
		else
			o_st += ap_hx_cd(st[i], buf, i + o_st);
		i++;
	}
	buf[i + o_st] = '\0';

	return (write(1, buf, i + o_st));
}
