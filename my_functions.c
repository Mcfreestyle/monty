#include "monty.h"

/**
 * is_number - checks if a string is a number
 * @s: string
 *
 * Return: 1 if the string is a number, otherwise 0
 */
int is_number(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	if (s[0] == '-')
		i = 1;

	for (; s[i]; i++)
	{
		if (isdigit(s[i]) == 0)
			return (0);
	}
	return (1);
}
