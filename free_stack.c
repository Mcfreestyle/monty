#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @top: pointer to the stack top
 */
void free_stack(stack_t *top)
{
	if (top == NULL)
		return;

	free_stack(top->next);
	free(top);
}
