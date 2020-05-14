#include "monty.h"

/**
 * clean - a function to free our stack
 * @stack: a pointer to our stack
 */

void clean(stack_t **stack)
{
	stack_t *tmp;
	if (stack == NULL)
		;
	else
	{
		tmp = (*stack);
		while ((*stack) != NULL)
		{
			(*stack) = (*stack)->prev;
			free(tmp);
			tmp = (*stack);
		}
		free(stack);
	}
}
