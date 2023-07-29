/**************START OF GUARD**********/
#ifndef MAIN_H
#define MAIN_H


/******** STDLIB.H FILES TO INCLUDE******/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**************MACROS USED**************/
#define fl_minas 1
#define fl_plas 2
#define fl_ziro 4
#define fl_ash 8
#define fl_spes 16

#define UNUSED(x)(void)(x)


#define PRINTF_BUFF_SIZE 1024

/**
 * int find_flgs(const char *format, int *index);
 * int g_width(const char *format, int *index, va_list lst_prnt);
 * int g_precision(const char *format, int *index, va_list lst_prnt);
 * int g_size(const char *format, int *index, va_list lst_prnt);
 */

#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct spec - Struct op
 * @spec: the format
 * @fn: function associate
 */

struct spec
{
	char spec;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct spec spec_t - Struct op
 *
 * @spec: format
 * @spec_t: function associated
 */

typedef struct spec spec_t;


/************PROTOTYPES***********/
int _printf(const char *format, ...);
int specifier_print(const char *spec, int *in_d, va_list lst_prnt, char buf[], int flags, int width, int precision, int size);
int display_char(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_str(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_integer(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_unsg_octal(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_percent(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_unsigned_integer(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_unsgn_upprhex(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_lowupper_hexa(va_list clas, char hold[], char buf[], int flags, int get_flagch, int width, int precision, int size);
int display_binary(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_hexadecimal(va_list clas, char buf[], int flags, int width, int precision, int size);
int g_precision(const char *format, int *i, va_list lst_prnt);
int find_flgs(const char *format, int *i);
int display_reverse(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_pointer(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_rot13s(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_n_printable(va_list clas, char buf[], int flags, int width, int precision, int size);
int g_width(const char *format, int *i, va_list lst_prnt);
int g_size(const char *format, int *i);
int is_print(char);
int ap_hx_cd(char, char[], int);
int i_digit(char);
long int csn(long int uli, int size);
long int csn_unsgnd(unsigned long int uli, int size);
int take_write_ch(char c, char buf[], int flags, int width, int precision, int size);
int  write_num(int neg, int in_d, char buf[], int flags, int width, int precision, int size);
int write_num1(int in_d, char buf[], int flags, int width, int prec, int length, char pad, char exc);
int write_unsgnd(int neg, int in_d, char buf[], int flags, int width, int precision, int size);
int write_pointer(char buf[], int in_d, int length, int width, int flags, char pad, char exc, int pads);
int specifier_print(const char *spec, int *in_d, va_list lst_prnt, char buf[], int flags, int width, int precision, int size);




/********END OF GUARD*********/
#endif
