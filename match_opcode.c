#include "monty.h"

/**
 * match_opcode - checks if the opcode exists
 * @opcode: instruction inside the file
 * @nb_line: opcode line number
 * @top: address of the stack top
 */
void match_opcode(char *opcode, int nb_line, stack_t **top)
{
	int i;
	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	for (i = 0; operations[i].opcode; i++)
	{
		if (strcmp(operations[i].opcode, opcode) == 0)
		{
			operations[i].f(top, nb_line);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", nb_line, opcode);
	free(buff);
	free_stack(*top);
	exit(EXIT_FAILURE);
}
