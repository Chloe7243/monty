#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stackLength <= 0)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	printf("%d\n", temp->n);
}
