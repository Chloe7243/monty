#include "monty.h"

/**
 * divide - function that divides the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 4. add
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stackLength < 2)
		throw_error("can't div, stack too short", line_number);
	if (temp->n == 0)
		throw_error("division by zero", line_number);

	temp->prev->n /= temp->n;
	pop(stack, line_number);
}

/**
 * pchar - prints char at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 4. add
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void pchar(stack_t **stack, unsigned int line_number)
{
        stack_t *temp = *stack;

        if (stackLength == 0)
                throw_error("can't pchar, stack empty", line_number);
        if (temp->n > 127 || temp->n < 0)
                throw_error("can't pchar, value out of range", line_number);

	printf("%c\n", temp->n);
}
