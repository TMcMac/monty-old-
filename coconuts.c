#include "monty.h"

/**
 * _pop - removes top node of stack
 * @stack: pointer to top node
 * @line_number: line number count for given file
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *mover;

	if ((*stack) == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->prev == NULL)
		free((*stack));
	else
	{
		mover = (*stack);
		(*stack) = (*stack)->prev;
		free(mover);
	}
}
