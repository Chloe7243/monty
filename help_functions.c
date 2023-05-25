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


/**
 *  _isdigit - Finds if char is a digit or not
 *
 *  @str: Character passed in
 *
 *  Return: 1 for digit, 0 if not
 */

int _isdigit(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (1);
		i++;
	}

	return (0);
}
