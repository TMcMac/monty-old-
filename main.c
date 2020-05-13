#include "monty.h"

#define STDERR FILENO_STDERR
/**
 *
 *
 *
 */

int main(int argc, char **argv)
{
	FILE *stream;
	char *line;
	size_t len = 60;
	char *arg[10];
	ssize_t nread = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		/* Our first check will be if we get ./monty and a file */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* If we have the correct number of args we will need to open the file */
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		/* if we cannot open the file for any reason we error */
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* If we have a file and we can open it we malloc our line to hold input from get line */
	line = malloc(sizeof(char) * 60);
	while (nread != -1)
	{
		nread = getline(&line, &len, stream);
		if (nread != -1)
		{
			line_number++;
			printf("Line %d : %s", line_number, line);
			(*arg) = strtok(line, " ");
			printf("STRTOK WORKS\n");
			opcode_comp((*arg), &stack, line_number);
			printf("OPCODE DOESNT\n");
			printf("ARG?: %s\n", *arg);
			/* Arg is our array of args, tokenized by strtok */
			/* We need to send arg array to an  execution function and return a 0/-1 success/fail */
			printf("Arg: %s\n", (*arg));
		}
		(*arg) = strtok(NULL, " \t");
	}


	free(line);
	fclose(stream);
	return (0);
}
