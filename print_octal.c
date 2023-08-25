#include "main.h"
/**
 * print_octal - print number from args in octal
 * @args: args to get next arg long int
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_octal(va_list *args, format_flags *flags)
{
	unsigned int n1;
	unsigned long int n2;
	unsigned short int n3;

	if (flags->l_flag)
	{
		n2 = va_arg(*args, unsigned long int);
		return (print_octal_main(n2, flags));
	}
	else if (flags->h_flag)
	{
		n3 = va_arg(*args, unsigned int);
		return (print_octal_main(n3, flags));
	}
	else
	{
		n1 = va_arg(*args, unsigned int);
		return (print_octal_main(n1, flags));
	}
}
/**
 * print_octal_main - print number in octal
 * @n: number to print in octal
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_octal_main(unsigned long int n, format_flags *flags)
{
	int i = 0, startPrintFlag = 0, length = 0;
	char *octal;

	if (n == 0)
	{
		add_buffer('0');
		return (1);
	}
	/*signed maxin long t need 22 octal digits*/
	/*extra digit for end of string*/
	octal = malloc(22 + 1);
	if (!octal)
		return (-2);
	convert_int_to_octal(octal, n);

	if (flags->hash_flag && n)
	{
		add_buffer('0');
	}
	i = 0;

	while (octal[i])
	{
		if (startPrintFlag == 0 && octal[i] != '0')
			startPrintFlag = 1;

		if (startPrintFlag == 1)
		{
			add_buffer(octal[i]);
			length++;
		}
		i++;
	}
	free(octal);

	return (length);
}
/**
 * convert_int_to_octal - convert integer to octal.
 * @octal: string to save octal value
 * @n: number to convert to octal in string
 * Return: void
 */
void convert_int_to_octal(char *octal, unsigned long int n)
{
	int i, size = 23;

	for (i = 0; i < size; i++)
		octal[i] = '0';
	octal[size] = '\0';

	/*convert to octal in string*/
	for (i = size - 1; n > 0; i--)
	{
		if (n == 8)
			octal[i] = '0';
		else if (n == 7)
			octal[i] = '7';
		else
			octal[i] = (n % 8) + '0';
		n /= 8;
	}
}
