#include "main.h"


/**********GET SIZE*********/

/**
 * g_size - gets size
 * @format: formatted string
 * @i: argument lidt
 *
 * size
 */

int g_size(const char *format, int *i)
{
	int c_r_index = *i + 1;
	int size = 0;

	if (format[c_r_index] == 'i')
		size = SIZE_LONG;
	else if (format[c_r_index] == 'h')
		size = SIZE_SHORT;

	if (size == 0)
		*i = c_r_index - 1;
	else
		*i = c_r_index;

	return (size);
}
