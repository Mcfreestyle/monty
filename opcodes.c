#include "monty.h"

/**
 * push - adds a new item to the stack
 * @stack: address of the stack top
 * @line_number: line number of the opcode
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_item;
	char *num;

	num = strtok(NULL, DELIMS);
	if (!num)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_item = malloc(sizeof(stack_t));
	if (!new_item)
		fprintf(stderr, "Error: malloc failed");

	new_item->n = atoi(num);
	new_item->prev = NULL;
	new_item->next = *stack;

	if (*stack)
		(*stack)->prev = new_item;

	*stack = new_item;
}

/**
 * pall - prints the stack items
 * @stack: address of the stack top
 * @line_number: line number of the opcode
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *item;
	(void) line_number;

	for (item = *stack; item; item = item->next)
		printf("%d\n", item->n);
}

