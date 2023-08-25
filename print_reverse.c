#include "main.h"

/**
 * print_reverse- print rotate string
 * @args: args to get next arg string
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_reverse(va_list *args, format_flags *flags)
{
	char *s = va_arg(*args, char *);
	int length = 0;
	(void) flags;

	if (!s)
		return (0);

	while (s)
	{
		length++;
		s++;
	}
	s--;
	while (s)
	{
		add_buffer(*s);
		s--;
	}
	return (length);
}
