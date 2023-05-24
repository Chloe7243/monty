#include "monty.h"

void push_int(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(args[1]);
	if (isStack)
	{
		new->next = NULL;
		if (*stack == NULL)
		{
			new->prev = NULL;
			*stack = new;
		}

		else
		{
			temp = *stack;
			while (temp->next)
				temp = temp->next;

			temp->next = new;
			new->prev = temp;
		}
	}
	else
	{
		new->next = (*stack);
		if (*stack != NULL)
			(*stack)->prev = new;
		(*stack) = new;
	}
	stackLength++;
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stackLength <= 0)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	if (isStack)
	{
		while (temp->next)
			temp = temp->next;
		temp->prev->next = temp->next;
		free(temp);
	}
	else
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
	}
	stackLength--;
}

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum;

	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next)
		temp = temp->next;
	sum = temp->prev->n + temp->n;
	printf("%d\n", sum);
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next)
		temp = temp->next;
	temp->prev->prev->next = temp;
	temp->prev->next = temp->next;
	temp->prev->prev = temp;
	temp->next = temp->prev;
	temp->prev = temp->prev->prev;
}

void display(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
