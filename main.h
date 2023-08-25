#ifndef MAIN_H
#define MAIN_H
#define INIT_FLAGS { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct format_flags - save matched flags of string.
 * @unsign_flag: save unsign flag
 * @zero_flag: save zero flag
 * @minus_flag: save zero flag
 * @plus_flag: save zero flag
 * @hash_flag: save zero flag
 * @space_flag: save zero flag
 * @h_flag: save zero flag
 * @l_flag: save zero flag
 * @width: save zero flag
 * @precision: save zero flag
 *
 */

typedef struct format_flags
{
	int unsign_flag;
	int zero_flag;
	int minus_flag;
	int plus_flag;
	int hash_flag;
	int space_flag;
	int h_flag;
	int l_flag;
	int width;
	int precision;
} format_flags;

/**
 * struct conversion_specifier - save matched conversion specifier of string.
 * @type: type of conversion specifier.
 * @struct format_prefix: A structure that holds a prefix and its length.
 * @handler: pointer to function to handle selected type.
 *
 */
typedef struct conversion_specifier
{
	char *type;
	int (*handler)();
} conversion_specifier;

int addStartToEndPrint(char *start, char *end);
int print_buffer(char *buffer, unsigned int bufferCount);
void add_buffer(char c);
int _printf(const char * const format, ...);
int print_ustring(va_list *args, format_flags *flags);
int print_string(va_list *args, format_flags *flags);
int print_char(va_list *args, format_flags *flags);
int print_percent(va_list *args, format_flags *flags);
int print_unsigned(va_list *args, format_flags *flags);
int print_unsigned_main(unsigned long int n, format_flags *flags);
int print_signed(va_list *args, format_flags *flags);
int print_signed_main(long int n, format_flags *flags);
void convert_int_to_octal(char *octal, unsigned long int n);
int print_octal(va_list *args, format_flags *flags);
int print_octal_main(unsigned long int n, format_flags *flags);
void convert_int_to_binary(char *binary, int n, int isNegative);
int print_binary(va_list *args, format_flags *flags);
int print_Uhexa(va_list *args, format_flags *flags);
int print_hexa(va_list *args, format_flags *flags);
int print_hexa_main(unsigned long int n, format_flags *flags, int isUpper);
void convert_int_to_hexa(char *hexa, unsigned long n, int isUpper);
int print_pointer(va_list *args, format_flags *flags);
int print_reverse(va_list *args, format_flags *flags);
int print_rotate(va_list *args, format_flags *flags);
int get_specifier(const char *format, va_list *args, format_flags *flags);
int get_flags(const char *format, format_flags *flags);
void get_width(va_list *args, const char *format, format_flags *flags);
void get_precision(va_list *args, const char *format, format_flags *flags);
void reset_format_flags(format_flags *flags);
int getStartEndLength(const char *start, const char *end);

#endif
