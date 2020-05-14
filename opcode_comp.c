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
	int i = 0, j = 0, k = 0, neg = 0, status;
	char num[11];
	instruction_t opcodes[] = {
		{"pall", _pall}, {"push", _push}, {"pint", _pint}, {"pop", _pop},
		{"add", _add}, {"sub", _sub}, {"div", _div}, {"mul", _mul}, {"nop", _nop}, 
		{"mod", _mod}, {NULL, NULL}
		/*
		 * {"swap", swap},
		*/
	};
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, arg) == 0)
		{
			if (strcmp(opcodes[i].opcode, "push") == 0)
			{
				while (isdigit(arg[j]) < 1 && arg[j] != 45)
					j++;
				if (arg[j] == 45)
				{
					neg = 1;
					j++;
				}
				while (arg[j] > 47 && arg[j] < 58 && k < 11)
				{
					num[k] = (arg[j]);
					k++;
					j++;
				}
				status = 0;
				Ni = atoi(num);
				if (neg == 1)
					Ni *= -1;
			}
			else
				status = check_exe(stack, line_number, arg);
			if (status == 0)
			{
				opcodes[i].f(stack, line_number);
				return (0);
			}
			else
			{
				exit(0);
				return (-1);
			}
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, arg);
	return (-1);
}
