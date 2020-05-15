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

/**
 * _swap - a function to swap the top node and second node in a stack
 * @stack: a pointer to the top of our stack
 * @line_number: the line number of the command that called swap
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->prev;
	stack_t *last = tmp->prev;
	(void) line_number;

	last->next = (*stack);
	tmp->prev = (*stack);
	(*stack)->prev = last;
	(*stack)->next = tmp;
	tmp->next = NULL;
	(*stack) = tmp;
}
