#include "monty.h"

/**
 * _add - adds top two nodes in stack
 * @stack: pointer to top node in stack
 * @line_number: line count for given file
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *mover = (*stack)->prev;
	int result = 0;
	(void) line_number;

	result = ((*stack)->n + mover->n);
	mover->n = result;
	mover = mover->next;
	(*stack) = (*stack)->prev;
	free(mover);

}

/**
 * _sub - subtracts the second element n from the top element n
 * @stack: pointer to top node in stack
 * @line_number: line count for given file
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *mover = (*stack)->prev;
	int result = 0;
	(void) line_number;

	result = ((*stack)->n - mover->n);
	mover->n = result;
	mover = mover->next;
	(*stack) = (*stack)->prev;
	free(mover);
}

/**
 * _div - divids the second n by the top n.
 * @stack: pointer to top node in stack
 * @line_number: line count for given file
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *mover = (*stack)->prev;
	int result = 0;
	(void) line_number;

	result = (mover->n / (*stack)->n);
	mover->n = result;
	mover = mover->next;
	(*stack) = (*stack)->prev;
	free(mover);

}

/**
 * _mul - multiplies the top two nodes in stack
 * @stack: pointer to top node in stack
 * @line_number: line count for given file
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *mover = (*stack)->prev;
	int result = 0;
	(void) line_number;

	result = ((*stack)->n * mover->n);
	mover->n = result;
	mover = mover->next;
	(*stack) = (*stack)->prev;
	free(mover);

}

/**
 * _mod - second n modulus top n
 * @stack: pointer to top node in stack
 * @line_number: line count for given file
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *mover = (*stack)->prev;
	int result = 0;
	(void) line_number;

	result = (mover->n % (*stack)->n);
	mover->n = result;
	mover = mover->next;
	(*stack) = (*stack)->prev;
	free(mover);

}
