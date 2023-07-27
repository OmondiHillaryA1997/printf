/**************START OF GUARD**********/
#ifndef MAIN_H
#define MAIN_H


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

#define UNUSED(m) (void)(m)


#define PRINTF_BUFF_SIZE 1024

int find_flgs(const char *format, int *index);
int g_width(const char *format, int *index, va_list lst_prnt);
int g_precision(const char *format, int *index, va_list lst_prnt);
int g_size(const char *format, int *index, va_list lst_prnt);

/************PROTOTYPES***********/
int _printf(const char *format, ...);
int g_prnt(const char *format, int *index, va_list lst_prnt, char buf[], int flags, int width, int precision, int size);
int display_char(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_write(char v_cls, char buf[], int flags, int width, int precision, int size);
int display_str(va_list clas, char buf[], int flags, int width, int precision, int size);
long int csn(long int li, int size);
int display_integer(va_list clas, char buf[], int flags, int width, int precision, int size);
int write_integer(int neg, int index, char buf[], int flags, int width, int recision, int size);
int display_unsg_octal(va_list clas, char buf[], int flags, int width, int precision, int size);
int write_unsinteger(va_list clas, int index, char buf[], int flags, int width, int precision, int size);
int display_percent(va_list clas, char buf[], int flags, int width, int precision, int size);
int diaplay_unsigned_integer(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_unsgn_upprhex(va_list clas, char buf[], int flags, int width, int precision, int size);
int write_hexdecim(va_list clas, const char *p, char buf[], int flags, int width, int precision, int size);
int display_lowupper_hexa(va_list clas, char hold[], char buf[], int flags, int get_flagch, int width, int precision, int size);
int display_binary(va_list clas, char buf[], int flags, int width, int precision, int size);
int display_hexadecimal(va_list clas, char buf[], int flags, int width, int precision, int size);


/********END OF GUARD*********/
#endif
