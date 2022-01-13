#include "monty.h"

/**
 * main - read the Monty ByteCode file and execute its opcodes
 * @argc: number of arguments
 * @argv: list of arguments
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	stack_t *top;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	top = NULL; /* create the stack */
	parse_file(argv[1], &top);

	free_stack(top);
	return (0);
}
