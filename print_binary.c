#include "main.h"
/**
 * print_binary - print int number from args in binary
 * @args: args to get next arg int
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_binary(va_list *args, format_flags *flags)
{
	int n = va_arg(*args, int);
	int i = 0, isnegative = 0, startPrintFlag = 0, length = 0;
	char *binary;

	if (n == 0)
	{
		add_buffer('0');
		return (1);
	}
	if (n < 0)
	{
		n = (-n) - 1;
		isnegative = 1;
	}
	binary = malloc(32 + 1);
	if (!binary)
		return (-2);
	convert_int_to_binary(binary, n, isnegative);
	if (flags->hash_flag)
		*--binary = '0';
	i = 0;
	while (binary[i])
	{
		if (startPrintFlag == 0 && binary[i] == '1')
			startPrintFlag = 1;
		if (startPrintFlag == 1)
		{
			add_buffer(binary[i]);
			length++;
		}
		i++;
	}
	free(binary);
	return (length);
}
/**
 * convert_int_to_binary - convert integer to binary.
 * @binary: string to save binary value
 * @n: number to convert to binary in string
 * @isNegative: flag for signed number
 * Return: void
 */
void convert_int_to_binary(char *binary, int n, int isNegative)
{
	int i, size = 32;

	for (i = 0; i < size; i++)
		binary[i] = '0';
	binary[size] = '\0';

	/*convert to binary in string*/
	for (i = size - 1; n > 0; i--)
	{
		binary[i] = (n % 2) + '0';
		n /= 2;
	}
	/* for negative number convert 1 , 0*/
	if (isNegative)
	{
		for (i = 0; binary[i]; i++)
		{
			if (binary[i] == '0')
				binary[i] = '1';
			else
				binary[i] = '0';
		}
	}
}
