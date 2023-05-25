#include "monty.h"

/**
 * free_stack - frees list
 * @stack: head pointer
 * Return: void
 */

void free_stack(stack_t *stack)
{
	while (stack)
	{
		free(stack);
		stack = stack->prev;
	}
}

/**
 * throw_error - dislays error message
 * @msg: error message
 * @lnum: line number of error
 * return void
 */

void throw_error(char *msg, int lnum)
{
	free_stack(head);
	fclose(fp);
	fprintf(stderr, "L%d: %s\n", lnum, msg);
	exit(EXIT_FAILURE);
}
