#include "monty.h"

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
		if ((*stack) == NULL || stack == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			status = -1;
		}
		else
			status = 0;
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		if ((*stack) == NULL || stack == NULL)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			status = -1;
		}
		else
		{
			status = 0;
		}
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		if ((*stack) == NULL || stack == NULL || (*stack)->prev == NULL)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
			status = -1;
		}
		else
			status = 0;
	}
	else if (strcmp(opcode, "add") == 0 || strcmp(opcode, "sub") == 0 || strcmp(opcode, "div") == 0 || strcmp(opcode, "mul") == 0 || strcmp(opcode, "mod") == 0)
	{
		if ((*stack) == NULL || stack == NULL || (*stack)->prev == NULL)
		{
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
			status = -1;
		} 
		else if (strcmp(opcode, "div") == 0 && (*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			status = -1;
		}
	}
	else if (strcmp(opcode, "pall") == 0 || strcmp(opcode, "nop") == 0)
	{
		status = 0;
	}

	return (status);
}
