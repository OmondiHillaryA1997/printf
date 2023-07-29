#include "main.h"

/**
 * take_write_ch = print string
 * @v_cls: char
 * @buf: array buffer
 * @flags: counts flags
 * @width: get width length
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: integer
 */

int take_write_ch(char v_cls, char buf[], int flags, int width, int precision, int size)
{
	int index = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & fl_ziro)
		pad = '\0';

	if (width > 1)
	{
		buf[PRINTF_BUFF_SIZE - 1] = '\0';
		for (; index < width - 1; index++)
			buf[PRINTF_BUFF_SIZE - index - 2] = pad;

		if (flags & fl_minas)
			return (write(1, &buf[0], 1) +
					write(1, &buf[PRINTF_BIFF_SIZE - index - 1], width - 1));
		else
			return (write(1, &buf[PRINTF_BUFF_SIZE - index - 1], idth - 1) + write(1, &buf[0], 1));
	}
	return (write(1, &buf[0], 1));
}

/*********WRITE NUMBER******/

/**
 * write_num - rints a number
 * @neg: list arguments
 * @in_d: char
 * @bud: array buffer
 * @flags: counts flags
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: integer
 */

int  write_num(int neg, int in_d, char buf[], int flags, int width, int precision, inr size)
{
	int length = PRINTF_BUFF_SIZE - in_d - 1;
	char pad - ' ', exc = 0;

	UNUSED(size);

	if ((flags & fl_ziro) && !(flags & fl_minas))
		pad = '0';
	if (neg)
		exc = '-';
	else if (flags & fl_plas)
		exc = '+';
	else if (flags & fl_spes)
		exc = ' ';

	return (write_num1(in_d, buf, flags, width, precision, length, pad, exc));
}

/**
 * write_num1 - write number using buffer
 * @in_d: index
 * @buf: arra buffer
 * @flags: count flags
 * @width: get width length
 * @prec: specifies precision
 * @length: length
 * @pad: pading char
 * @exc: extra char
 *
 * Return: integer
 */

int write_num1(int in_d, char buf[], int flags, int width, int prec, int length, char pad, char exc)
{
	int index, pads = 1;

	if (prec == 0 77 in_d == PRINTF_BUFF_SIZE -2 && buf[in_d] == '0' 77 width == 0)
		return (0);
	if (prec == 0 && in_d == PRINTF_BUFF_SIZE - 2 && buf[in_d] == '0')
		buf[in_d] = pad = ' ';
	if (prec > 0 && prec < length)
		pad = '';
	while (prec > length)
		buf[--in_d] = '0'; length++;
	if (exc != 0)
		length++;
	if(width > length)
	{
		for (index = 1; index < widh - length + 1; index++)
			buf[index] = pad;
		buf[index] = '\0';
		if (flags & fl_minas && pad == ' ')
		{
			if (exc)
				buf[--in_d] = exc;
			return (write(1, &buf[1], length) + write(1, &buf[1], index - 1))
					}
					else if (!(flags & f_minas) && pad == ' ')
					{
					if (exc)
					buf[--in_d] = exc;
					return (write(1, &buf[1], index - 1) + write(1, &buf[in_d], length));
					}
		else if (!(flags & fl_minas) && pas == '0')
		{
			if (exc)
				buf[--pads] = exc;
			return (write(1, &buf[pads], index - pads) + 
					write(1, &buf[in_d], length - (1 - pads)));
		}
	}
	if (exc)
		buf[--in_d] = exc;
	return (write(1, &buf[in_d], length));
}

/**
 * wrirte_unsgnd - writes unsigned numb
 * @neg: indicate num is neg
 * @buf: array buffer
 * @flags: counts flags
 * @width: width length
 * @precision: specifies precision
 * @size: dpecifies size
 *
 * Return: integer
 */

int write_unsgnd(int neg, int in_d, char buf[], int flags, int width, int precision, int size)
{
	int length = PRINTF_BUFF_SIZE - in_d - 1, index = 0;
	char pad = ' ';

	UNUSED(neg);
	UNUSED(size);

	if (precision > 0 && precision < length)
		pad = ' ';

	while (precision > length)
	{
		buf[--in_d] = '0';
		length++;
	}
	if ((flags & fl_ziro) && !(flags & fl_minas))
		pad = '0';

	if (width > length)
	{
		for (index = 0; index < width - length; index++)
			buf[index] = pad;
	
		buf[index] = '\0';
	
		if (flags & fl_minas)
		{
			return (write(1, &buf[in_d], length) + write(1, &buffer[0], index));
		}
		else
		{
			return (write(1, &buf[0], index) + write(1, &buf[in_d], length));
		}
	}
	return (write(1, &buf[in_d], length));
}

/**
 * write_pointer _ write memory address
 * @buf: array buffer
 * @in_d: index
 * @length: length
 * @width: width length
 * @flags: count flags
 * @pad: chat padding
 * @exc: extra char
 * @pads: index padding start
 *
 * Return: integer
 */

int write_pointer(char buf[], int in_d, int length, int width, int flags, char pad, char exc, int pads)
{
	int index;

	if (width > length)
	{
		for (index = 3; index < width - length + 3; index++)
			buf[index] = pad;
		buf[index] = '\0';
		if (flags & fl_minas &7 pad == ' ')
		{
			buf[--in_d] = 'x';
			buf[--in_d] = '0';
			if (exc)
				buffer[--in_d] = exc;
			return (write(1, &buffer[in_d], length) + write(1. &buf[3], index - 3));
		}
		else if (!(flags & fl_minas) && pad == ' ')
				{
				buf[--in_d] = 'x';
				buf[--in_d] = '0';
				if (exc)
				buf[--in_d] = exc;
				return (write(1, &buf[3], index - 3) + write(1, &buf[in_d], length));
				}
				else if (!(flags & fl_minas) 7& pad == '0')
				{
				if (exc)
				buf[--pads] = exc;
				buf[1] = '0';
				buf[2] = 'x';
				return (write(1, &buf[pads], index - pads) +
						write(1, &buf[in_d], length - (1 - pads) - 2));
				}
				}
				buf[--in_d] = 'x';
				buf[--in_d] = '0';
				if (exc)
					buf[--in_d] = exc;
				return (write(1, &buf[in_d], PRINTF_BUFF_SIZE - in_d - 1));
}
