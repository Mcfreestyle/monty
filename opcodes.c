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
	if (!num || !(is_number(num)))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(buff);
		free_stack(*stack);
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

/**
 * pint - prints the value of the stack top
 * @stack: address of the stack top
 * @line_number: line number of the opcode
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - deletes the stack top
 * @stack: address of the stack top
 * @line_number: line number of the opcode
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(buff);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: address of the stack
 * @line_number: line_number of the opcode
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top2, *top1, *top3;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(buff);
		free(*stack);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = top1->next;
	top3 = top2->next;

	top2->prev = NULL;
	top2->next = top1;

	top1->prev = top2;
	top1->next = top3;

	if (top3 != NULL)
		top3->prev = top1;

	*stack = top2;
}
