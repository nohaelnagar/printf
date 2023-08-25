#include "main.h"
#include <stdio.h>
/**
 * print_pointer - print pointer address of input
 * @args: args to get next arg int
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_pointer(va_list *args, format_flags *flags)
{
	void *ptr;
	unsigned long int_input;
	int i, length, startPrintFlag = 0;
	char *hexa;
	(void) flags;
	ptr = (va_arg(*args, void *));

	if (ptr == NULL)
	{
		char *temp = "(nil)";

		for (i = 0; temp[i]; i++)
			add_buffer(temp[i]);
		return (5);
	}
	int_input = (unsigned long)ptr;
	/*signed maxint need 16 hexa digits*/
	/*extra digit for end of string*/
	hexa = malloc(16 + 1);
	if (!hexa)
		return (-2);
	convert_int_to_hexa(hexa, int_input, 0);
	add_buffer('0');
	add_buffer('x');
	i = 0, length = 2;
	while (hexa[i])
	{
		if (startPrintFlag == 0 && hexa[i] != '0')
			startPrintFlag = 1;
		if (startPrintFlag == 1)
		{
			add_buffer(hexa[i]);
			length++;
		}
		i++;
	}
	free(hexa);
	return (length);
}
