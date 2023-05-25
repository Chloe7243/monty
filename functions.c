#include "monty.h"
#define MAX_LENGTH 256

int isStack = 1, stackLength = 0;
stack_t *head = NULL;
char *args[2];
FILE *fp;

/**
 * process_file - processes monty bytecode file
 * @filename: file
 *
 * Return: void
 */

void process_file(char *filename)
{
	int line_num = 1;
	char line[MAX_LENGTH];

	fp = fopen(filename, "r");
	if (fp != NULL)
	{

		while (fgets(line, sizeof(line), fp) != NULL)
		{
			split(line, line_num);
			if (strcmp(args[0], "queue") == 0)
				isStack = 0;
			get_function(args[0], line_num);
			line_num++;
		}
		free_stack(head);
		fclose(fp);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
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
	int i = 0, exists = 0;

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
			exists = 1;
		}
		i++;
	}

	if (exists == 0)
	{
		fclose(fp);
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
	char *token, trim[5], *text;
	int i = 0, j, k = 0;

	token = strtok(line, " ");
	while (token != NULL && i < 2)
	{
		if (i == 0)
		{
			if (strcmp(token, " ") != 0)
			{
				text = token;
				for (j = 0; text[j] != '\0'; j++)
				{
					if (isalpha(text[j]))
					{
						trim[k] = text[j];
						k++;
					}
				}
				trim[k] = '\0';
				args[0] = trim;
				i++;
			}
		}
		else if (args[0] && strcmp(args[0], "push") == 0)
		{
			if (atoi(token) || strcmp(token, "0") == 0)
			{
				args[1] = token;
				i++;
			}
			else
				throw_error("usage: push integer", line_num);
		}
		else
			i++;
		token = strtok(NULL, " ");
	}
}
