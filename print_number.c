#include "main.h"
/**
 * print_unsigned - print unsigned number from args
 * @args: args to get next arg int
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_unsigned(va_list *args, format_flags *flags)
{
	unsigned int n1;
	unsigned long int n2;
	unsigned short int n3;

	if (flags->l_flag)
	{
		n2 = va_arg(*args, unsigned long int);
		return (print_unsigned_main(n2, flags));
	}
	else if (flags->h_flag)
	{
		n3 = va_arg(*args, unsigned int);
		return (print_unsigned_main(n3, flags));
	}
	else
	{
		n1 = va_arg(*args, unsigned int);
		return (print_unsigned_main(n1, flags));
	}
}
/**
 * print_unsigned_main - print unsigned number
 * @n: number to print
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_unsigned_main(unsigned long int n, format_flags *flags)
{
	unsigned long int last, remain = n, i = 0, temp = 1;

	(void) flags;
	/* get how many 0s in number */
	while (remain / 10 != 0)
	{
		remain = remain / 10;
		temp = temp * 10;
	}
	/* print number from left to right */
	remain = n;
	while (temp > 0)
	{
		if (remain < temp)
			add_buffer('0');
		else
		{
			last = remain / temp;
			add_buffer(last + '0');
			remain = remain - (last * temp);
		}
		temp /= 10;
		i++;
	}

	return (i);
}
/**
 * print_signed- print number from args
 * @args: args to get next arg int
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_signed(va_list *args, format_flags *flags)
{
	int n1;
	long int n2;
	short int n3;

	if (flags->l_flag)
	{
		n2 = va_arg(*args, long int);
		return (print_signed_main(n2, flags));
	}
	else if (flags->h_flag)
	{
		n3 = va_arg(*args, int);
		return (print_signed_main(n3, flags));
	}
	else
	{
		n1 = va_arg(*args, int);
		return (print_signed_main(n1, flags));
	}
}
/**
 * print_signed_main - print number
 * @n: number to print
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_signed_main(long int n, format_flags *flags)
{
	long int last, remain = n, i = 0, temp = 1;
	int isNegative = 1;

	/* handle negative numbers */
	if (n < 0)
	{
		add_buffer('-');
		i++;
		isNegative = -1;
	}
	else if (flags->plus_flag)
	{
		add_buffer('+');
		i++;
	}
	/* get how many 0s in number */
	while (remain / 10 != 0)
	{
		remain = remain / 10;
		temp = temp * 10;
	}
	/* print number from left to right */
	remain = n;
	while (temp > 0)
	{
		if ((remain < 0 && remain > -temp) || (remain > 0 && remain < temp))
			add_buffer('0');
		else
		{
			last = remain / temp;
			add_buffer(isNegative * last + '0');
			remain = remain - (last * temp);
		}
		temp /= 10;
		i++;
	}

	return (i);
}
