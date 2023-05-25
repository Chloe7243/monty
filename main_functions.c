#include "monty.h"

stack_t *queue;

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
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		free_stack(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(args[1]);
	if (isStack)
	{
		new->next = NULL;
		new->prev = *stack;
		if (*stack)
			(*stack)->next = new;
		else
			queue = new;
		*stack = new;
	}
	else
	{
		new->next = (queue);
		new->prev = NULL;
		if (queue)
			(queue)->prev = new;
		(queue) = new;
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
	stack_t *ptr = *stack;

	if (stackLength <= 0)
		throw_error("can't pop an empty stack", line_number);

	else if (isStack)
	{
		*stack = ptr->prev;
		if (*stack)
			(*stack)->next = NULL;
		free(ptr);
	}
	else
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
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

	if (stackLength < 2)
		throw_error("can't add, stack too short", line_number);

	temp->prev->n += temp->n;
	pop(stack, line_number);
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
	stack_t *ptr = *stack, *ptr2;

	if (stackLength < 2)
		throw_error("can't swap, stack too short", line_number);

	ptr2 = ptr->prev;

	if (ptr2->prev)
		ptr2->prev->next = ptr;

	ptr->prev = ptr2->prev;
	ptr2->prev = ptr;
	ptr->next = ptr2;
	ptr2->next = NULL;
	*stack = ptr2;

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
		temp = temp->prev;
	}
}
