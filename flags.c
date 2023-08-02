#include "main.h"

/***********GET FLAGS************/

/**
 * find_flgs - gets flags
 * @format: formatted string
 * @index: argument list to be printed
 *
 * Return: flags
 */

int find_flgs(const char *format, int *i)
{
	int g, c_r_index, flags = 0;
	const char  flgs_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flgs_ar[] = {fl_minas, fl_plas, fl_ziro, fl_ash, fl_spes, 0};

	for (c_r_index = *i + 1; format[c_r_index] != '\0'; c_r_index++)
	{
		for (g = 0; flgs_ch[g] != '\0'; g++)
			if (format[c_r_index] == flgs_ch[g])
			{
				flags |= flgs_ar[g];
				break;
			}
		if (flgs_ch[g] == 0)
			break;

	}

	*i = c_r_index - 1;
	return (flags);
}
