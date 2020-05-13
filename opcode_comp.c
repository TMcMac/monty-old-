void opcode_comp(char *arg, stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes = [] {
		{"pull", pull}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"add", add}, {"swap", swap},
		{"nop", nop}, {"sub", sub},
		{"div", div}, {"mul", mul},
		{NULL, NULL}
	}
	if (opcodes[i] != NULL)
	{
		if (strcmp(opcodes[i], arg) == 0)
		{
			opcodes.f(stack, line_number);
		}
		else
		{
			fprintf(STDERR, "L%d: uknown instruction %s\n", line_number, arg);
			exit(EXIT_FAILURE);
		}
	}
}
