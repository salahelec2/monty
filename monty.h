#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_var - golbal variables
 * @file: file name
 * @buffer: fgets buffer
 * @tmp: fgets counter
 * @dict: instruction dictionary
 * @head: pointer to a list
 * @line_number: current line
 * @MODE: Program configuration stack or queue
 */
typedef struct glob_var
{
	FILE *file;
	char *buffer;
	size_t tmp;
	instruction_t *dict;
	stack_t *head;
	unsigned int line_number;
	int MODE;
} vars;

extern vars gvar;

int start_vars(vars *var);
instruction_t *create_instruction();
int function_call(vars *var, char *opcode);
void free_all(void);
int _isdigit(char *string);

void op_pall(stack_t **, unsigned int);
void op_push(stack_t **, unsigned int);
void op_pint(stack_t **, unsigned int);
void op_pop(stack_t **, unsigned int);
void op_swap(stack_t **, unsigned int);

#endif
