#include "main.h"
#include <unistd.h>

/**
 * print_string - writes the string from args to stdout
 * @args: args to get next arg char*
 * @flags: flags for format string
 * Return: number of printed charagcters
 */
int print_string(va_list *args, format_flags *flags)
{
	char *s = va_arg(*args, char *);
	int i = 0;

	(void) flags;
	if (s == NULL)
	{
		s = "(null)";
	}

	while (*s)
	{
		add_buffer(*s);
		s++;
		i++;
	}
	return (i);
}
/**
 * print_char - writes the char from args to stdout
 * @args: args to get next arg char
 * @flags: flags for format string
 * Return: On success 1
 */
int print_char(va_list *args, format_flags *flags)
{
	char s = va_arg(*args, int);
	(void) flags;
	add_buffer(s);

	return (1);
}
/**
 * print_percent - writes % to stdout
 * @flags: flags for format string
 * @args: args to get next arg char*
 * Return: On success 1
 */
int print_percent(va_list *args, format_flags *flags)
{
	(void) flags;
	(void) args;
	add_buffer('%');
	return (1);
}
/**
 * print_ustring - prints a string and ASCII of non printed characters
 * @args: args to get next arg char*
 * @flags: flags for format string
 * Return: number of printed charagcters
 */
int print_ustring(va_list *args, format_flags *flags)
{
	unsigned char *str;
	char *hexa;
	int i = 0, length;

	(void) flags;
	str = va_arg(*args, unsigned char *);
	hexa = malloc(sizeof(char) * (8 + 1));
	if (!hexa)
		return (-2);

	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			add_buffer('\\');
			add_buffer('x');

			convert_int_to_hexa(hexa, str[i], 1);

			/*print last two digits in hexa*/
			add_buffer(hexa[14]);
			add_buffer(hexa[15]);

			length += 4;
		}
		else
		{
			add_buffer(str[i]);
			length++;
		}
		i++;
	}
	free(hexa);
	return (length);
}
