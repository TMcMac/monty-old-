#include "monty.h"

/**
 * opcode_comp - compare arg to avaiable op codes
 * @stack: pointer to top of stack
 * @line_number: line_number counter
 * @arg: parsed getline for opcode and args
 * Return: Nothing
 */

void opcode_comp(char *arg, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	int j;
	instruction_t opcodes[] = {
		{"pall", _pall},
		{"push", _push},
		{"pint", _pint},
	        {"pop", _pop},
		{"add", _add},
		/* {"swap", swap},
		 * {"nop", nop},
		 * {"sub", sub},
		 * {"div", div},
		 * {"mul", mul},
		*/
		{NULL, NULL}
	};
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, arg) == 0)
		{
			if (strcmp(opcodes[i].opcode, "push") == 0)
			{
				while (isdigit(arg[j]) < 1)
				{
					j++;
				}
				Ni = (arg[j] - 48);
			}
			opcodes[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, arg);
	exit(EXIT_FAILURE);
}
