#include "monty.h"

/**
 * getpushint - helper for push opcode args
 * @arg: argument from getline
 * @line_number: line count of given file
 * Return:  status integer
 */

int getpushint(char *arg, unsigned int line_number)
{
	int status, j = 0, k = 0, neg = 0;
	char num[11];

	while (arg[j])
	{
		j++;
	}
	while (arg[j] == 32 || arg[j] == 9 || arg[j] == 0)
	{
		j++;
	}
	if (arg[j] == 45)
	{
		neg = 1;
		j++;
	}
	if (isdigit(arg[j]))
	{
		while (arg[j] > 47 && arg[j] < 58 && k < 11)
		{
			num[k] = (arg[j]);
			k++;
			j++;
		}
		Ni = atoi(num);
		if (neg == 1)
			Ni *= -1;
		status = 0;
	}
	else
	{
		status = -1;
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
	}
	return (status);
}
