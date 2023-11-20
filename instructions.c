#include "monty.h"


/**
 * instruction - execute the opcode
 * @buff: string pointer the line to execute.
 * @ln: line being execute.
 * @stack: stack to visit.
 */
void instruction(char *buff, stack_t *stack, size_t ln)
{
	char *token;
	int i = 1;
	instruction_t opc[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},{"pop", pop},
		{"swap", swap}, {"add", add}, {"sub", sub}, {"div", mydiv},
		{NULL, NULL}
	};

	token = strtok(buff, " \n\t");
	printf("token %s", token);
	if (strcmp(token , "push") == 0)
	{
		token = strtok(NULL, " \n\t");
		if (check(token))
		{
			gval.ab = atoi(token);
			opc[0].f(&stack, ln);
		}
		else
		{
			fprintf(stderr, "L%ld: usage: push integer", ln);
			gval.exitflag = 1;
		}
		return;
	}
	else if(token)
	{
		while (opc[i].opcode)
		{
			if (strcmp(token, opc[i].opcode) == 0)
			{
				opc[i].f(&stack, ln);
				return;
			}
			i++;
		}
		if (opc[i].opcode == NULL)
		{
			fprintf(stderr, "L%ld: unknown instruction %s",ln, token);
			gval.exitflag = 1;
		}
	}

}

/**
 * check - check if push argument is a number.
 * @str: the string pointer.
 * Return: the string if true or string if false
 */

char *check(char *str)
{
	int i = 0;

	if (!str)
		return (NULL);

	while (str[i])
		if (str[0] == '-')
		{
			continue;
			i++;
		}
	{
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
	}
	return (str);
}
