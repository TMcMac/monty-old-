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
	int opINT = 0;
	instruction_t opcodes[] = {
		{"pall", _pall},
	       	{"push", _push},
		{"pint", _pint},
/**
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		*/
		{NULL, NULL}
	};
	printf("before FOR LOOP\n");
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		printf("IN FOR LOOP BEFORE STRCMP");
		if (strcmp(opcodes[i].opcode, arg) == 0)
		{
			if (strcmp(opcodes[i].opcode, "push") == 0)
			{
				printf("AM I IN SECOND STRCMP");
				arg++;
				if (isdigit(arg) > 0)
				{
					opINT = atoi(arg);
				}
				printf("OPINT = %d\n", opINT);
			}
			opcodes[i].f(stack, line_number);
			return;
		}
	}
       			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, arg);
			exit(EXIT_FAILURE);
}
