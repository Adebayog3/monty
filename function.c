#include "monty.h"

/**
*@push - the name of the function
*@stack_t **stack- doublr pointer
*@unsigned int line- the line number in the code
*@return- does not return a value
*/

void push(stack_t **stack, unsigned int line)
{
    stack_t *new_node = malloc(sizeof(stack_t *)), *temp = NULL;

	(void)line;
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        gval.exitflag = 1;
        return;
    }
    new_node->n = gval.ab;
    if (gval.order)
    {
        new_node->prev = NULL;
		new_node->next = *stack;

		if (*stack)
			(*stack)->prev = new_node;

		*stack = new_node;
	}
	else
	{
		if (*stack)
		{
			while (temp->next)
				temp = temp->next;

			temp->next = new_node;
			new_node->prev = temp;
			new_node->next = NULL;
		}
		else
		{
			*stack = new_node;
			new_node->next = NULL;
			new_node->prev = NULL;
		}

    }

}

/**
*@pall- the name of the function
*@stack_t **stack- a double pointer
*@unsigned int line_number- the line in the code
*@return- does not return a value
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (!*stack)
		return;

	temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
*@pint- the name of the function
*@ stack_t **stack- a double pointer
*@unsigned int line_number- the line in the code 
*@ return- does not return a value
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		gval.exitflag = 1;
		return;
	}

	printf("%d\n", (*stack)->n);
}

/**
*@nop- name of the function
*@stack_t **stack- a double pointer
*@unsigned int line_number- line number in the code
*@ return- does not return a value
*/

void nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}

/**
*@add- this is the function name for addition
*@ stack_t **stack- a double pointer
*@unsigned int line_number- line number in the code
*@return- does not return a value
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	size_t len = 0;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		gval.exitflag = 1;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n += temp->n;
	free(temp);
}
