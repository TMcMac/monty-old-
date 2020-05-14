#include "monty.h"

/**
 * clean - a function to free our stack
 * @stack: a pointer to our stack
 */

void clean(stack_t **stack)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	while ((*stack) != NULL)
	{
		tmp = (*stack);
		(*stack) = (*stack)->prev;
		if (tmp)
			free(tmp);
	}
	free(*stack);
}
