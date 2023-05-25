#include "monty.h"

/**
 * push - function that pushes an element onto top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 0. push, pall
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void push(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
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

/**
 * pop - function that pops the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 2. pop
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stackLength <= 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
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

/**
 * add - function that adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 4. add
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum;

	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next)
		temp = temp->next;
	sum = temp->prev->n + temp->n;
	printf("%d\n", sum);
}

/**
 * swap - function that swaps the top two elements on the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 3. swap
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
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

/**
 * display - function that prints all elements on the stack
 * @stack: pointer to head of the stack
 * @line_number: where the instruction appears
 * Description: 0. push, pall
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */

void display(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
