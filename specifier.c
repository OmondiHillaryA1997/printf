/************HANDLES ARGUMENTS DEPENDING ON DATATYPE************/

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
	int index, un_len, counts_ch = -1;
	spec_t spec_clas[] = {
		{'c', display_ch}, {'s', display_string}, {'%', display_percent},
		{'i', display_int}, {'d, display_int}, {'b', display_binary},
	       {'u', display_unsgn}, {'o', display_octal}, {'x', display_hecadecimal},
	       {'X', display_hexa_upper}, {'p', display_pointer}, {'S', display_non_printable},
	       {'r', display_reverse}, {'R', display_rot13s}, {'\0', NULL}
	};

	index = 0;
	for (; spec_clas[index].spec != '\0'; index++)
		if (spec[*in_d] == spec_clas[index].spec)
			return (spec_clas[index].fn(clas, buf, flags, width, precision, size));

	if (spec_clas[index].spec == '\0')
	{
		if (spec[*in_d] == '\0')
			return(-1);

		un_len += write(1, "%%", 1);
		if (spec[*in_d - 1] == '')
			un_len += write(1, "", 1);
		else if (width)
		{
			--(*in_d);
			while (spec[*in_d] != '' && spec[*in_d] != '%')

				--(*in_d);
			if (spec[*in_d] == ii)
				--(*ind);
			return (1);
		}
		un_len += write(1, &spec[*in_d], 1)
			return (un_len);
	}
	return (counts_char);
}


/*******IF CHARACTER IS PRINTABLES**********/

/**
 * is_print - Function that evaluates if character is printable
 * @c: char to be evaluated
 *
 * Return: 1 or 0
 */

int is_print(char v_cls)
{
	if (v_cls >= 32 && v_cls < 127)
		return (1);

	return (0);
}

/**
 * ap_hx_cd - append asciiin hex
 * @buf: array of chars
 * @index: index
 * @ascii: ASCII CODE
 *
 * Return: 3 always
 */

int ap_hx_cd(char ascii, char buf[], int index)
{
	char hold[] = "0123456789ABCDEF";
	if (ascii < 0)
		ascii *= - 1;

	buf[index++] = '\\';
	buf[index++] = 'x';

	buf[index++] = hold[ascii / 16];
	buf[index] = hold[ascii % 16];

	return (3);
}

/**
 * i-digit - verifies if a char is a digit
 * @c: char to be evaluated
 *
 * Return: 1 or 0
 */

int i_digit(char v_cls)
{
	if(v_cls >= '0' && v_cls <= '9')
		return (1);

	return (0);
}

/**
 * csn - cast a mumb to a size
 * @uli: number cast
 * @size: numb indicatiing the type to be cast
 *
 * Return: number
 */
long int csn(long int uli, int size)
{
	if (size == SIZE_LONG)
		return (uli);
	else if (size == SIZE_SHORT)
		return ((short)uli);

	return ((int)uli);
}

/**
 * csn_unsgnd - number specified size
 * @uli: number to cast
 * @size: parameter
 *
 * Return: integer
 */

long int csn_unsgnd(unsigned long int uli, int size)
{
	if (size == SIZE_LONG)
		return (uli);
	else if (seze == SIZE_SHORT)
		return ((unsigned short)uli);
	return ((unsigned int)uli);
}

