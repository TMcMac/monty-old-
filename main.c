#include "monty.h"
int Ni;

/**
 * main - the main function for out monty code interpreter
 * @argc: the number of args we take in, must be two
 * @argv: an array of arguments, program name and file name
 * Return: 0 for success
 */

int main(int argc, char **argv)
{
	int status;
	FILE *stream;
	const char *filename = argv[1];
	char *line, *arg;
	size_t len = 60;
	ssize_t nread = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char delimit[] = " \t\r\n\v\f";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream)
		checkstream(stream, filename);
	line = malloc(sizeof(char) * 60);
	if (line == NULL)
	{
		freehelper(stream, line);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream) != -1))
	{
		line_number++;
		arg = strtok(line, delimit);
		if (arg)
			status = opcode_comp(arg, &stack, line_number);
		arg = strtok(NULL, delimit);
		if (status == -1)
			break;
	}
	clean(&stack);
	freehelper(stream, line);
	if (status == -1)
		exit(EXIT_FAILURE);
	return (0);
}
