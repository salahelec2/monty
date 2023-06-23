#include "monty.h"

/* is_ascii - s
 * @c: Double linked list
 * Return: 1 if is ascii, 0 otherwise
 */
int is_ascii(int c)
{
    return (c >= 0 && c <= 127) ? 1 : 0;
}

/**
 * op_pchar - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        free_all(), exit(EXIT_FAILURE);
    }
    if (is_ascii((*stack)->n))
    {
        printf("%c\n", (*stack)->n);
        return;
    }
    fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
    free_all(), exit(EXIT_FAILURE);
}

/**
 * op_pstr - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    (void)line_number;

    if (!stack || !*stack)
    {
        putchar('\n');
        return;
    }
    while (tmp)
    {
        if (tmp->n == 0)
            break;
        if (!is_ascii((tmp)->n))
            break;
        putchar(tmp->n);
        tmp = tmp->next;
    }
    putchar('\n');
}

/**
 * rotl - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *tm = *stack;
    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;
    (*stack)->next->prev = NULL;
    while (tm->next)
        tm = tm->next;
    tm->next = *stack;
    (*stack) = (*stack)->next;
    tm->next->next = NULL;
    tm->next->prev = tm;
}

/**
 * rotr - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = *stack;
    tmp->prev->next = NULL;
    tmp->prev = NULL;

    (*stack)->prev = tmp;
    *stack = tmp;
}

