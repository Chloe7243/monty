#include "monty.h"

/**
 * free_stack - frees list
 * @stack: head pointer
 * Return: void
 */

void free_stack(stack_t *stack)
{
	if (stack)
	{
		free_stack(stack->prev);
		free(stack);
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
