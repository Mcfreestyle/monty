#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: address of the stack
 * @line_number: line number of the opcode
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;

	if (!(*stack) || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		free(buff);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top1 = *stack;
	top2 = (*stack)->next;

	top2->n = top1->n + top2->n;
	top2->prev = NULL;
	*stack = top2;
	free(top1);
}
