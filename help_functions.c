#include "monty.h"

/**
 * free_stack - frees list
 * @head: head pointer
 * Return: void
 */

void free_stack(stack_t *head)
{
	while (head)
	{
		free(head);
		head = head->next;
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
	fclose(fp);
	free_stack(head);
	fprintf(stderr, "L%d: %s\n", lnum, msg);
	exit(EXIT_FAILURE);
}
