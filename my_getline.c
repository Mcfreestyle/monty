#include "monty.h"

/**
 * my_getline - the first line of the buffer is assigned to the variable line
 * @line: address of the variable line
 * @n: address of the buffer position
 * @buff: address of the buffer that contains the content of the file
 *
 * Return: read bytes of the line
 */
int my_getline(char **line, int *n, char **buff)
{
	int init_pos, end = 1, rbytes;

	if (*n == -1)
		return (-1);
	if (*n != 0)
		(*n)++;
	init_pos = *n;
	for (; (*buff)[*n]; (*n)++)
	{
		if ((*buff)[*n] == '\n')
		{
			end = 0;
			break;
		}
	}
	*line = *buff + init_pos;
	rbytes = *n - init_pos;
	(*buff)[*n] = '\0';
	if (end == 1)
		*n = -1;

	return (rbytes);
}
