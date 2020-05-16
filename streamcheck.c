#include "monty.h"

/**
 * checkstream - checks if file has permissions and mem
 * @stream: file to be checked
 * @filename: access const char to check permission
 */

void checkstream(FILE *stream, const char *filename)
{
	if (access(filename, R_OK) == -1)
	{
		fclose(stream);
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	if (stream == NULL)
	{
		fclose(stream);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
