#include "main.h"

/**
 * _printf - print strings to console.
 * @format: string with format to be printed.
 * Return: length of printed string.
 */
int _printf(const char *const format, ...)
{
	const char *start, *c;
	format_flags flags = INIT_FLAGS;
	int length = 0, newLength = 0;
	va_list args;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	for (c = format + 0; *c; c++)
	{
		reset_format_flags(&flags);
		if (*c == '%')
		{
			start = c, c++;
			if (!*c)
			{
				length++;
				break;
			}
			while (get_flags(c, &flags))
				c++;
			newLength = get_specifier(c, &args, &flags);
			if (newLength == -1)
				newLength = getStartEndLength(start, c);
			else if (newLength == -2)
				return (-1);
			length += newLength;
			continue;
		}
		add_buffer(*c), length++;
	}
	add_buffer(0), va_end(args);
	return (length);
}

int getStartEndLength(const char *start, const char *end)
{
	int length = 0;

	while (start <= end)
	{
		if (*start != 'l' && *start != 'h')
			add_buffer(*start), length++;
		start++;
	}
	return length;
}
