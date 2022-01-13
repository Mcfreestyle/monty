#include "monty.h"

/**
 * match_opcode - checks if the opcode exists
 * @opcode: instruction inside the file
 * @nb_line: opcode line number
 * @buff: buffer with the content of the file
 */
void match_opcode(char *opcode, int nb_line, char *buff)
{
	int i;
	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; operations[i].opcode; i++)
	{
		if (strcmp(operations[i].opcode, opcode) == 0)
		{
			operations[i].f(&top, nb_line);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", nb_line, opcode);
	free(buff);
	free_stack(top);
	exit(EXIT_FAILURE);
}
