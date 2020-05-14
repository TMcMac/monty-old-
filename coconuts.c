#include "monty.h"

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *mover;
	
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
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
