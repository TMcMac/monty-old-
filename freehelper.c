#include "monty.h"

/**
 * freehelper - frees stream and line
 * @stream: file to be closed
 * @line: line to be freed
 */

void freehelper(FILE *stream, char *line)
{
	if (line)
		free(line);
	if (stream)
		fclose(stream);
}
