#include "monty.h"
#define MAX_LENGTH 256

int isStack = 1, stackLength = 0;
stack_t *head = NULL;
char *args[2];

/**
 * process_file - processes monty bytecode file
 * @filename: file
 *
 * Return: void
 */

void process_file(char *filename)
{
	FILE *fp;
	int line_num = 1;
	char line[MAX_LENGTH];

	fp = fopen(filename, "r");
	if (fp != NULL)
	{

		while (fgets(line, sizeof(line), fp) != NULL)
		{
			split(line, line_num);
			if (strcmp(args[0], "queue"))
				isStack = 0;
			get_function(args[0], line_num);
			line_num++;
		}
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	if (fclose(fp) == EOF)
	{
		fprintf(stderr, "Error: Can't close file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * get_function - gets corresponding function for each code
 * @name: command
 * @line_num: where the instruction appears
 *
 * Return: void
 */

void get_function(char *name, int line_num)
{
	int i = 0;

	instruction_t cmds[] = {
		{"pall", display},
		{"push", push},
		{"pint", pint},
		{"swap", swap},
		{"pop", pop},
		{"add", add},
		{NULL, NULL}
	};

	while (i < 6)
	{
		if (strcmp(cmds[i].opcode, name) == 0)
		{
			cmds[i].f(&head, line_num);
		}
		i++;
	}

	if (i == 6)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, name);
		exit(EXIT_FAILURE);
	}
}

/**
 * split - splits line of code
 * @line: line of code
 * @line_num: where the instruction appears
 *
 * Return: void
 */

void split(char *line, int line_num)
{
	char *token;
	int i = 0;

	token = strtok(line, " ");
	while (token != NULL && i < 2)
	{
		if (i == 0)
		{
			if (strcmp(token, " ") != 0)
			{
				args[0] = token;
				i++;
			}
		}
		else if (strcmp(args[0], "push") == 0)
		{
			if (atoi(token))
			{
				args[1] = token;
				i++;
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
		}
		else
			break;
		token = strtok(NULL, " ");
	}
}
