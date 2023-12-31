#include "main.h"

/*************DISPLAYING A CHARACTER**************/

/**
 * display_char - Function that prints a character
 *
 * @clas: list of arguments
 * @buf: array buffer
 * @flags: counts flags
 * @width: wwidth length
 * @precision: specifies precision
 * @size: specifies size
 * 
 * Return: integer
 */

int display_char(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	char c = va_arg(clas, int);

	return (take_write_ch(c, buf, flags, width, precision, size));
}

/****************DISPLAYING STRING**************/

/**
 * display_str - Function that print a string
 *
 * clas: list of argumrnts
 * @buf: array buffer
 * @flags: count flags
 * @width: width length
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: integer
 */

int display_str(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	int length = 0, i = 0;
	char *st = va_arg(clas, char *);

	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (st == NULL)
	{
		st = "(null)";
		if (precision > 5)
			st = " ";
	}

	while (st[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if(width > length)
	{
		if (flags & fl_minas)
		{
			write(1, &st[0], length);
			i = (width - length);
			while (i > 0)
				write(1, "", 1);
			i--;

			return(width);
		}
		else
		{
			i = (width - length);
			while (i > 0)
			{
				write(1, "", 1);
				write(1, &st[0], length);
				return (width);
			}
			i--;
		}
	}
	return (write(1, st, length));
}

/*********DISPLAY INTEGER***********/

/**
 * display_integer - Function that prints an integer
 * @clas: list of arguments
 * @buf: array buffer
 * @flags: count flags
 * @width: get width
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: integer
 */

int display_integer(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	int i = PRINTF_BUFF_SIZE - 2;
	int neg;
	long int li = va_arg(clas, long int);
	unsigned long int uli;

	li = csn(li, size);

	if (li == 0)
		buf[i--] = '0';

	buf[PRINTF_BUFF_SIZE - 1] = '\0';
	uli = (unsigned long int)li;

	if(li < 0)
	{
		uli = (unsigned long int)((-1) * li);
		neg = 1;
	}

	while (uli > 0)
	{
		buf[i--] = (uli % 10) + '0';
		uli /= 10;
	}
	i++;

	return (write_num(neg, i, buf, flags, width, precision, size));
}

/************DISPLAY UNSIGNED OCTAL************/

/**
 * display_unsg_octal - printf function that prints octal
 * @clas: displays arguments
 * @buf: array buffer
 * @flags: counts arguments
 * @width: get width size
 * @precision: specifies precision
 * @size: specfies size
 *
 * Return: integer
 */

int display_unsg_octal(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	int i = PRINTF_BUFF_SIZE - 2;
	unsigned long int uli  = va_arg(clas, unsigned long int);
	unsigned long int uli_1 = uli;

	UNUSED(width);

	uli = csn_unsgnd(uli, size);

	if (uli == 0)
		buf[i--] = '0';

	buf[PRINTF_BUFF_SIZE - 1] = '\0';

	while (uli > 0)
	{
		buf[i--] = (uli % 8) + '0';
		uli /= 8;
	}

	if ((flags & fl_ash) && (uli_1) != 0)
		buf[i--] = '0';
	i++;

	return (write_unsgnd(0, i, buf, flags, width, precision, size));
}

/*********DISPLAY PERCENT SIGN**********/

/**
 * display_percent - Function that prints percentile
 * @clas: list of arguments
 * @buf: array buffer
 * @flags: count flags
 * @width: width size
 * @precision: specifies precision
 * @size: specifies size
 * 
 * Return: integer
 */

int display_percent(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	UNUSED(clas);
	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return(write(1, "%%", 1));
}

/************DISPLAY UNSIGNED INTEGER************/

/**
 * display_unsigned_integer - Function that prints unsigned integer
 *
 * @clas: displays arguments
 * @buf: array buffer
 * @flags: counts arguments
 * @width: gets width size
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: integer
 */

int display_unsigned_integer(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	int i = PRINTF_BUFF_SIZE - 2;
	unsigned long int uli = va_arg(clas, unsigned long int);

	uli = csn_unsgnd(uli, size);

	if (uli == 0)
		buf[i--] = '0';

	buf[PRINTF_BUFF_SIZE - 1] = '\0';

	while (uli > 0)
	{
		buf[i--] = (uli % 10) + '0';
		uli /= 10;
	}
	i++;

	return (write_unsgnd(0, i, buf, flags, width, precision, size));

}

/************DISPLAY UNSIGNED UPPER HEXADECIMAL NUMBER************/

/**
 * display_unsgn_upprhex - printf function that prints unsugned number upper hexadecimal
 * @clas: display arguments
 * @buf: array buffer
 * @flags: counts arguments
 * @width: get size width
 * @precision: specifies precision
 * @size: get size
 *
 * Return: integer
 */

int display_unsgn_upprhex(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	return (display_lowupper_hexa(clas, "0123456789ABCDEF", buf, flags, 'X',  width, precision, size));
}

/**********DISPLAY LOWER_UPPER HEXADECIMAL***********/

/**
 * display_lowuppr_hexa - Printf function that prints lower and upper hexadecimal
 *
 * @clas: displays arguments
 * @hold: value array
 * @buf: array buffer
 * @flags: count flagsi
 * @get_flagch: count flags
 * @width: get size width
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: integer
 */

int display_lowupper_hexa(va_list clas, char hold[], char buf[], int flags, int get_flagch, int width, int precision, int size)
{
	int i;
	unsigned long int uli;
	unsigned long int uli_1;
	i = PRINTF_BUFF_SIZE - 2;
	uli = va_arg(clas, unsigned long int);
	uli_1= uli;

	UNUSED(width);

	uli =  csn(uli,size );

	if (uli == 0)
		buf[i--] = '0';
	buf[PRINTF_BUFF_SIZE - 1] = '\0';

	while (uli > 0)
	{
		buf[i--] = hold[uli % 16];
		uli /= 16;
	}

	if (flags & fl_ash && uli_1 != 0)
	{
		buf[i--] = get_flagch;
		buf[i--] = '0';
	}
	i++;

	return (write_unsgnd(0, i, buf, flags, width, precision, size));

}

/************DISLAY_BINARY***************/

/**
 * display_binary - Function that prints unsigned number
 * @clas: list of argumens
 * @buf: array buffer
 * @flags: count flags
 * @width: get width size
 * @precision: specifies precision
 * @size: specifies length
 *
 * Return: integer
 */

int display_binary(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	unsigned int li, t, i, sum;
	unsigned int a[32];
	int cnt;

	UNUSED(buf);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	li = va_arg(clas, unsigned int);
	t = 2147483648;
	a[0] = li / t;
	for (i = 1; i < 32; i++)
	{
		t /= 2;
		a[i] = (li / t) % 2;
	}
	i = 0;
	sum = 0;
	cnt = 0;
	for(; i < 32; i++)
	{
		sum = a[i];
		if ((sum) || (i ==32))
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			cnt++;
		}
	}
	return (cnt);
}



/************DISPLAY HEXADECIMAL**************/

/**
 * display_hexadecimal - printf finction that prints hexadecimal
 * 
 * @clas: display arguments
 * @buf: array buffer
 * @flags: counts flags
 * @width: get size width
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: integer
 */

int display_hexadecimal(va_list clas, char buf[], int flags, int width, int precision, int size)
{
	return (display_lowupper_hexa(clas, "0123456789abcdef", buf, flags, 'x',  width, precision, size));
}
