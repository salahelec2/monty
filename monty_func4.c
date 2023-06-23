#include "monty.h"

/**
 * op_stack - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
    (void)line_number, (void)stack;

    gvar.MODE = 0;
}

/**
 * op_queue - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
    (void)line_number, (void)stack;

    gvar.MODE = 1;
}
