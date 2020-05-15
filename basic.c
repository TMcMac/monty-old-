#include "monty.h"

/**
 * _push - a function to add nodes to our stack
 * @stack: a pointer to the top of our stack
 * @line_number: the line number for the opcode that call this
 */


void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newtop;
	(void) line_number;

	newtop = malloc(sizeof(stack_t) * 1);
	if (newtop == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if ((*stack) == NULL || stack == NULL)
	{
		newtop->next = NULL;
		newtop->prev = NULL;
		newtop->n = Ni;
		(*stack) = newtop;
	}
	else
	{
		(*stack)->next = newtop;
		newtop->prev = (*stack);
		newtop->next = NULL;
		newtop->n = Ni;
		(*stack) = newtop;
	}
}

/**
 * _pall - a function to print all values in the stack
 * @stack: a pointer to our stack
 * @line_number: the line number for the opcode that got us here
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *mover = *stack;
	(void) line_number;

	while (mover != NULL)
	{
		printf("%d\n", mover->n);
		mover = mover->prev;
	}
}

/**
 * _pint - a fuction to print the top node's n value
 * @stack: a pointer to the top of our stack
 * @line_number: our line number for this command
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * _nop - opcode function that does nothing
 * @stack: top pointer of stack
 * @line_number: line count from given file
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void) **stack;
	(void) line_number;
}
