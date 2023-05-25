#include "monty.h"

/**
 * pint - function that prints the top element on the stack
 * @stack: pointer to head of the stack
 * @line_number: where the instruction appears
 * Description: 1. pint
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void pint(stack_t __attribute__((unused)) **stack, unsigned int line_number)
{
	stack_t *temp = sTail;

	if (stackLength <= 0)
		throw_error("can't pint, stack empty", line_number);
	else
		printf("%d\n", temp->n);
}
