/*******IF CHARACTER IS PRINTABLES**********/

#include "main.h"

/**
 * is_print - Function that evaluates if character is printable
 * @c: char to be evaluated
 *
 * Return: 1 or 0
 */

int is_print(char c)
{
	if (c >= 32 && c < 127)
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

int ap_hx_cd(char ascii, char buf[], int i)
{
	char hold[] = "0123456789ABCDEF";
	if (ascii < 0)
		ascii *= - 1;

	buf[i++] = '\\';
	buf[i++] = 'x';

	buf[i++] = hold[ascii / 16];
	buf[i] = hold[ascii % 16];

	return (3);
}

/**
 * i-digit - verifies if a char is a digit
 * @c: char to be evaluated
 *
 * Return: 1 or 0
 */

int i_digit(char c)
{
	if(c >= '0' && c <= '9')
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
	else if (size == SIZE_SHORT)
		return ((unsigned short)uli);
	return ((unsigned int)uli);
}
