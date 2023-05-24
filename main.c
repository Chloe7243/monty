#include "monty.h"

/**
 * main - checks program args
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		process_file(argv[1]);
	}

	return (0);
}
