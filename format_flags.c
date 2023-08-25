#include "main.h"
/**
 * reset_format_flags - print pointer address of input
 * @flags: A pointer to the format structure
 * that holds the flags for the output
 * Return: number of characters printed
 */
void reset_format_flags(format_flags *flags)
{
	flags->unsign_flag = 0;
	flags->zero_flag = 0;
	flags->minus_flag = 0;
	flags->plus_flag = 0;
	flags->hash_flag = 0;
	flags->space_flag = 0;
	flags->h_flag = 0;
	flags->l_flag = 0;
	flags->width = 0;
	flags->precision = UINT_MAX;
}
