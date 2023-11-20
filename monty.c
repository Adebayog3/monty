#include "monty.h"

data_t gval;

/**
 * main - entry point
 * @argc: argument count
 * @argb: argument vector
 *Return: always return success.
 */

int main(int argc, char **argb)
{
	FILE *fptr = NULL;
	stack_t *stack = NULL;
	unsigned int line = 1;
	size_t num;
	char *buff;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argb[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argb[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buff, &num, fptr) != -1)
	{
		printf("loop: %s\n", buff);
		if (buff[0] == '#')
		{
			line++;
			continue;
		}
		instruction(buff, stack, line);
		line++;
	}
	fclose(fptr);
	exit(EXIT_SUCCESS);
}
