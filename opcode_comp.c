#include "monty.h"

/**
 * opcode_comp - compare arg to avaiable op codes
 * @stack: pointer to top of stack
 * @line_number: line_number counter
 * @arg: parsed getline for opcode and args
 * Return: Nothing
 */

int opcode_comp(char *arg, stack_t **stack, unsigned int line_number)
{
	int i = 0, status;
	instruction_t opcodes[] = {
		{"pall", _pall}, {"push", _push}, {"pint", _pint},
		{"pop", _pop}, {"add", _add}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"nop", _nop}, {"mod", _mod},
		{"swap", _swap}, {NULL, NULL}
	};
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, arg) == 0)
		{
			if (strcmp(opcodes[i].opcode, "push") == 0)
			{
				status = getpushint(arg, line_number);
			}
			else
				status = check_exe(stack, line_number, arg);
			if (status == 0)
			{
				opcodes[i].f(stack, line_number);
				return (0);
			}
			/*
			 *else
			 *	{
			 *	exit(0);
			 *	return (-1);
			 *	}
			 */
		}
	}
	/*
	 *fprintf(stderr, "L%u: unknown instruction %s\n", line_number, arg);
	 */
	return (-1);
}
