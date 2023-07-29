/**************START OF GUARD**********/
#ifndef "MAIN_H"
#define "MAIN.H"


/******** STDLIB.H FILES TO INCLUDE******/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**************MACROS USED**************/
#define fl_minas 1
#define fl_plas 2
#define fl_ziro 4
#define fl_ash 8
#define fl_spes 16

#define UNUSED(x)(void)(x)


#define BUFF_SIZE 1024

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
int g_prnt(const char *format, int &index, va_list lst_prnt, char buf, int flags, int width, int precision, int size);
int display_char(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_str(va_list clas, char buf[], int flags, int width, int precision int size);
int display_integer(va_list clas, char buf[], int flags, int width, int size);
int display_char(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_str(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_integer(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_unsg_octal(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_percent(va_list clas, char buf[], int flags, int width, int precision, int size);
int diaplay_unsigned_integer(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_unsgn_upprhex(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_lowupper_hexa(va_list clas, char hold, char buf[], int flags, int get_flagch, int precision, int size);
int display_binary(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_hexadecimal(va_list clas, char buf[], int flags, int width, int precision, int size);
int write_char_handler(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_pos, int ind, char buffer[], int flags, int width, int precision, int size);
int write_numb(int ind, char buff[], int flags, int width, int precision, int length, char extra_c, char padd);
int write_pointer(int ind, char buffer[], int length, int width, int flags, char padd, char extra_c, int padd_start);
int write_unsg(int is_neg, int ind, char buffer[], int flags, int width, int precision, int size);
int display_lowupper_hexa(va_list clas, char hold[], char buf[], int flags, int get_flagch, int width, int precision, int size);
int display_binary(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_hexadecimal(va_list clas, char buf[], int flags, int width, int precision, int size);
int g_precision(const char *format, int *index, va_list lst_prnt);
int find_flgs(const char *format, int *index);
int display_reverse(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_pointer(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_rot13s(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_n_printable(va_list clas, char buf[], int flags, int width, int precision, int size);
int g_width(const char *format, int *index, va_list lst_prnt);
int g_size(const char *format, int *index);
int specifier_print(const char *spec, int *in_d, va_list lst_prnt, char buf[], int flags, int width, int precisio, int size);



/********END OF GUARD*********/
#endif
