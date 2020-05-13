#include "monty.h"

/**
 * _push - a function to add nodes to our stack
 * @stack: a pointer to the top of our stack
 * @line_number: the line number for the opcode that call this
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newtop;
	(void) unsigned int line_number;

	newtop = malloc(sizeof(stack_t) * 1);
	if (newtop == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if ((*stack) == NULL)
	{
		newtop->next = NULL;
		newtop->prev = NULL;
		newtop->n = 0 /*NEED N FROM ARGS, GLOBAL VAR?*/;
		(*stack) = newtop;
	}
	else
	{
		(*stack)->next = newtop;
		newtop->prev = (*stack);
		newtop->next = NULL;
		newtop->n = 0 /*NEED N FROM ARGS*/;
		(*stack) = newtop;
	}
	return;
}

/**
 * _pall - a function to print all values in the stack
 * @stack: a pointer to our stack
 * @line_number: the line number for the opcode that got us here
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *mover;
	int sum;
	(void) unsigned int line_number;

	if ((*stack) == NULL)
	{
		return;
	}
	else
	{
		while (mover != NULL)
		{
			printf("%d\n", mover->n);
			mover = mover->prev;
		}
	}
	return;
}

/**
 *
 *
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
}
