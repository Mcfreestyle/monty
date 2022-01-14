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

/**
 * nop - it doesn't do anything
 * @stack: address of the stack
 * @line_number: line number of the opcode
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element from the second top element of the stack
 * @stack: address of the stack
 * @line_number: line number of the opcode
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;

	if (!(*stack) || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		free(buff);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top1 = *stack;
	top2 = (*stack)->next;

	top2->n = top2->n - top1->n;
	top2->prev = NULL;
	*stack = top2;
	free(top1);
}

/**
 * div - divides the second top element by the top element of the stack
 * @stack: address of the stack
 * @line_number: line number of the opcode
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;

	if (!(*stack) || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		free(buff);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top1 = *stack;
	top2 = (*stack)->next;

	if (top1->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		free(buff);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	top2->n = top2->n / top1->n;
	top2->prev = NULL;
	*stack = top2;
	free(top1);
}

/**
 * mul - multiplies the second top element with the top element of the stack
 * @stack: address of the stack
 * @line_number: line number of the opcode
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;

	if (!(*stack) || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		free(buff);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top1 = *stack;
	top2 = (*stack)->next;

	top2->n = top2->n * top1->n;
	top2->prev = NULL;
	*stack = top2;
	free(top1);
}
