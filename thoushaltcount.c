#include "monty.h"

/**
 * _add - adds top two nodes in stack
 * @stack: pointer to top node in stack
 * @line_number: line count for given file
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *mover;
	int result = 0;

	if ((*stack) == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		mover = (*stack)->prev;
		result = ((*stack)->n + mover->n);
		mover->n = result;
		mover = mover->next;
		(*stack) = (*stack)->prev;
		free(mover);
	}
}
