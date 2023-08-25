#include "main.h"


/**
 * add_buffer - concatenates the buffer characters
 * @c: charcter to concatenate
 * Return: void
 */
void add_buffer(char c)
{
	static char buffer[1024];
	static int bufferCount;

	/* reset buffer if get to 1024*/
	if (bufferCount == 1024 || !c)
	{
		write(1, buffer, bufferCount);
		bufferCount = 0;
	}

	buffer[bufferCount] = c;
	bufferCount = bufferCount + 1;
}
