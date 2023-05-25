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

void pint(stack_t **stack, unsigned int line_number)
{
	if (stackLength <= 0)
		throw_error("can't pint, stack empty", line_number);
	else
		printf("%d\n", (*stack)->n);
}

/**
 * nop - does nothinh
 * @stack: pointer to head of the stack
 * @line_number: where the instruction appears
 * Description: 1. pint
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub - function that subtracts the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 4. add
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stackLength < 2)
		throw_error("can't sub, stack too short", line_number);

	temp->prev->n -= temp->n;
	pop(stack, line_number);
}

