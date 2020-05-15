#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

extern int Ni; /* Global Variable for int argument */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* This is our checker program */
int check_exe(stack_t **stack, unsigned int line_number, char *opcode);
/* This is our program with opecodes struct*/
int opcode_comp(char *arg, stack_t **stack,  unsigned int line_number);
/* These are all mover our functions in basic*/
void _push(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);

/* These are the math functions in thoushaltcount  */
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

/* This function does nothing.... why does it exist? */
void _nop(stack_t **stack, unsigned int line_number);

/* This is our memory clean up program */
void clean(stack_t **stack);

/*  This is our program to check file permissions  */
void checkstream(FILE *stream, const char *filename);

int getpushint(char *arg, unsigned int line_number);
#endif
