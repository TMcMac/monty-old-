#include "monty.h"

int checkmaths(stack_t **stack, unsigned int line_number, char *opcode);
int checkmovers(stack_t **stack, unsigned int line_number, char *opcode);

/**
 * check_exe - checks to see if the conditions are correct to
 * execute the given monty call. If the conditions are wrong
 * print an error message and set status -1 else status = 0.
 * @stack: a pointer to our stack
 * @line_number: the line number for the command that got us here
 * @opcode: the call or command that we are currently checking
 * Return: 0 means we can execute, -1 is a fail condition
 */

int check_exe(stack_t **stack, unsigned int line_number, char *opcode)
{
	int status;

	if (strcmp(opcode, "pint") == 0)
	{
		if (stack == NULL || (*stack) == NULL)
		{
			dprintf(2, "L%u: can't pint, stack empty\n", line_number);
			status = -1;
		}
		else
			status = 0;
	}
	else if (strcmp(opcode, "pop") == 0)
		status = checkmovers(stack, line_number, opcode);
	else if (strcmp(opcode, "swap") == 0)
		status = checkmovers(stack, line_number, opcode);
	else if (strcmp(opcode, "add") == 0 || strcmp(opcode, "sub") == 0)
		status = checkmaths(stack, line_number, opcode);
	else if (strcmp(opcode, "div") == 0 || strcmp(opcode, "mul") == 0)
		status = checkmaths(stack, line_number, opcode);
	else if (strcmp(opcode, "mod") == 0)
		status = checkmaths(stack, line_number, opcode);
	else if (strcmp(opcode, "pall") == 0 || strcmp(opcode, "nop") == 0)
	{
		status = 0;
	}
	return (status);
}



/**
 * checkmaths - a function to check the stack to see if we can run our
 * math checks correctly
 * @stack: a pointer to the top of out stack
 * @line_number: the line number of the call that brought us here
 * @opcode: the call we are working on
 * Return: 0 for good to go or -1 for there is an error
 */
int checkmaths(stack_t **stack, unsigned int line_number, char *opcode)
{
	int status = 0;

	if (stack == NULL || (*stack) == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, opcode);
		status = -1;
	}
	else if (strcmp(opcode, "div") == 0 && (*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		status = -1;
	}
	return (status);
}

/**
 * checkmovers - a function to check the stack to see if we can run our
 * math checks correctly
 * @stack: a pointer to the top of out stack
 * @line_number: the line number of the call that brought us here
 * @opcode: the call we are working on
 * Return: 0 for good to go or -1 for there is an error
 */

int checkmovers(stack_t **stack, unsigned int line_number, char *opcode)
{
	int status = 0;
	stack_t *a = (*stack);

	if ((strcmp(opcode, "pop") == 0) && (stack == NULL || *stack == NULL))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		status = -1;
	}
	else if (strcmp(opcode, "swap") == 0 && (a == NULL || a->prev == NULL))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		status = -1;
	}

	return (status);
}
