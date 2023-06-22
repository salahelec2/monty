#include "monty.h"

/**
 * op_add - add the top two elements of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	op_pop(stack, line_number);
}
