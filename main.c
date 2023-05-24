#include "monty.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("hi %s\n", argv[1]);
	}

	return (0);
}
