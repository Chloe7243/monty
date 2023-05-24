#include "monty.h"

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
