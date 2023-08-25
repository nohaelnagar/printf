#include "main.h"
/**
 * print_hexa - print number from args in hexa
 * @args: args to get next arg int
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_hexa(va_list *args, format_flags *flags)
{
	unsigned int n1;
	unsigned long int n2;
	unsigned short int n3;

	if (flags->l_flag)
	{
		n2 = va_arg(*args, unsigned long int);
		return (print_hexa_main(n2, flags, 0));
	}
	else if (flags->h_flag)
	{
		n3 = va_arg(*args, unsigned int);
		return (print_hexa_main(n3, flags, 0));
	}
	else
	{
		n1 = va_arg(*args, unsigned int);
		return (print_hexa_main(n1, flags, 0));
	}
}
/**
 * print_Uhexa - print number from args in hexa upper
 * @args: args to get next arg int
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_Uhexa(va_list *args, format_flags *flags)
{
	unsigned int n1;
	unsigned long int n2;
	unsigned short int n3;

	if (flags->l_flag)
	{
		n2 = va_arg(*args, unsigned long int);
		return (print_hexa_main(n2, flags, 1));
	}
	else if (flags->h_flag)
	{
		n3 = va_arg(*args, unsigned int);
		return (print_hexa_main(n3, flags, 1));
	}
	else
	{
		n1 = va_arg(*args, unsigned int);
		return (print_hexa_main(n1, flags, 1));
	}
}
/**
 * print_hexa_main - main function to handle print hexa
 * @n: number to print in hexa
 * @flags: flags for format string
 * @isUpper: a flag indicating whether to use uppercase letters
 * Return: number of characters printed
 */
int print_hexa_main(unsigned long int n, format_flags *flags, int isUpper)
{
	int i = 0, startPrintFlag = 0, length = 0;
	char *hexa;

	if (n == 0)
	{
		add_buffer('0');
		return (1);
	}

	/*signed maxint need 16 hexa digits*/
	/*extra digit for end of string*/

	hexa = malloc(16 + 1);
	if (!hexa)
		return (-2);
	convert_int_to_hexa(hexa, n, isUpper);
	if (flags->hash_flag && n)
	{
		add_buffer('0');

		if (isUpper)
			add_buffer('X');
		else
			add_buffer('x');
	}
	i = 0;
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
/**
 * convert_int_to_hexa - convert integer to hexa.
 * @hexa: string to save hexa value
 * @n: number to convert to hexa in string
 * @isUpper: a flag indicating whether to use uppercase letters
 * Return: void
 */

void convert_int_to_hexa(char *hexa, unsigned long n, int isUpper)
{
	int i, size = 16, letterbase;

	for (i = 0; i < size; i++)
		hexa[i] = '0';
	hexa[size] = '\0';

	if (isUpper)
		letterbase = 55;
	else
		letterbase = 87;

	/*convert to hexa in string*/
	for (i = size - 1; n > 0; i--)
	{
		if ((n % 16) > 9)
			hexa[i] = (n % 16) + letterbase;
		else
			hexa[i] = (n % 16) + '0';

		n /= 16;
	}
}
