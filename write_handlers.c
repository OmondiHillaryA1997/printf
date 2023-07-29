#include "main.h"

/**********WRITE HANDLERS**********/
/**
 * write_char_handler - Prints a string
 * @c: types of char
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: specification of Precision
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int write_char_handler(char c, char buffer[],
		int flags, int width, int precision, int size)
{ /* char is stores at the left and padded at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/********** WRITE NUMBER**********/
/**
 * write_number - Prints a string
 * @is_neg: List of arguments
 * @ind: types of char
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: specification of Precision
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int write_number(int is_neg, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_neg)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_numb(ind, buffer, flags, width, precion,
				length, padd, extra_ch));
}

/**
 * write_numb - Write a number using buffer
 * @ind: starting index of number on the  buffer
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: Width
 * @prec: Precision specifier
 * @length: Length
 * @padd: Padding char
 * @extra_c: extra char
 *
 * Return: Number of printed chars
 */
int write_numb(int ind, char buffer[], int flags, int width, int prec,
		int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /*printf(".0d", 0) no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /*width is printed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
		if (extra_c)
		buffer[--padd_start] = extra_c;
	return (write(1, &buffer[padd_start], i - padd_start) +
		write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of char
 * @ind: starting index for the number in the buffer
 * @length: length
 * @width: width
 * @flags: flags
 * @padd: char for padding
 * @extra_c: char for extra char
 * @padd_start: starting index for padding
 *
 * Return: Number of written chars
 */
int write_pointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
			/* Assign extra char to the left of buffer*/
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/*extra char to left of buffer*/
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/*extra char to left of padd*/
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';

	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

/**
 * write_unsg - Writes an unsigned number
 * @is_neg: Number indicating negative num
 * @ind: starng index of number in buffer
 * @buffer: Arrays of chars
 * @flags: Flags
 * @width: width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars
 */
int write_unsg(int is_neg, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	/* Number is stored at the right of the buffer and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
char padd = ' ';

UNUSED(is_neg)
	UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
	return (0); /*printf(".0d", 0) no char is printed */

if (precision > 0 && precision < length)
	padd = ' ';

while (precision > length)
{
	buffer[--ind] = '0';
	length++;
}

if ((flags & F_ZERO) && !(flags & F_MINUS))
	padd = '0';

	if (width > length)
{
	for (i = 0; i < width - length; i++)
		buffer[i] = padd;

	buffer[i] = '\0';

	if (flags & F_MINUS)
		/* Assign extra char to the left of buffer [buffer>padd]*/
	{
		return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
	}
	else /* Assign extra char to the left of the padding [add>buffer]*/
	{
		return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
	}
}
return (write(1, &buffer[ind], length));
}


