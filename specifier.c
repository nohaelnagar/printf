#include "main.h"
/**
 * get_specifier - get specifier handler from string
 * @format: formatted string
 * @args: args to get next arg
 * @flags: a bitmask of flags that modify the output
 * Return: handler function
 */
int get_specifier(const char *format, va_list *args, format_flags *flags)
{
	int j = 0;
	conversion_specifier specifiers[] = {
		{"s", print_string}, {"c", print_char},
		{"%", print_percent}, {"d", print_signed},
		{"i", print_signed}, {"u", print_unsigned},
		{"o", print_octal}, {"x", print_hexa},
		{"X", print_Uhexa}, {"b", print_binary},
		{"S", print_ustring}, {"p", print_pointer}
	};
	if (!*format)
		return (0);
	while (j < 12)
	{
		if (specifiers[j].type[0] == *format)
			return (specifiers[j].handler(args, flags));
		j++;
	}

	return (-1);
}
/**
 * get_flags - get specifier handler from string
 * @format: formatted string
 * @flags: format flags to update
 * Return: void
 */
int get_flags(const char *format, format_flags *flags)
{
	int i = 1;

	if (!*format)
		return (0);

	if (!*format)
		return (0);

	switch (*format)
	{
		case '+':
			flags->plus_flag = 1;
			break;
		case ' ':
			flags->space_flag = 1;
			break;
		case '#':
			flags->hash_flag = 1;
			break;
		case '-':
			flags->minus_flag = 1;
			break;
		case '0':
			flags->zero_flag = 1;
			break;
		case 'h':
			flags->h_flag = 1;
			break;
		case 'l':
			flags->l_flag = 1;
			break;
		default:

			i = 0;
	}

	format = format + i;

	return (i);
}

/**
 * get_width - get specifier handler from string
 * @format: formatted string
 * @args: args to get next arg
 * @flags: format flags to update
 * Return: void
 */
void get_width(va_list *args, const char *format, format_flags *flags)
{
	int width = 0;
	char start = '0';

	if (!*format)
		return;
	if (*format == '*')
	{
		width = va_arg(*args, int);
		format++;
		return;
	}
	else
	{
		while (*format > start && *format <= '9')
		{
			width = width * 10 + (*format - '0');
			format++;

			if (start == '0')
				start--;
		}
	}
	flags->width = width;
}

/**
 * get_precision - get specifier handler from string
 * @args: args to get next arg
 * @format: formatted string
 * @flags: format flags to update
 * Return: void
 */
void get_precision(va_list *args, const char *format, format_flags *flags)
{
	char start = '0';
	int precision = 0;

	if (!*format)
		return;


	if (*format != '.')
		return;

	format++;

	if (*format == '*')
	{
		precision = va_arg(*args, int);
		format++;
		return;
	}
	else
	{
		while (*format > start && *format <= '9')
		{
			precision = precision * 10 + (*format - '0');
			format++;

			if (start == '0')
				start--;
		}
	}
	flags->precision = precision;
}
