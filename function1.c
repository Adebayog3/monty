#include "monty.h"

/**
*@pop: prints the top
*@stack_t: stack head
*@line_number: line number
*@return: void
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		gval.exitflag = 1;
		return;
	}

	*stack = (*stack)->next;
	free(temp);
}

/**
*@swap: swaps the top two element of the stack
*@stack_t: head of the stack
*@line_number: line_number
*@return: void
*/

void swap(stack_t **stack, unsigned int line_number)
{
	size_t len = 0;
	stack_t *temp = *stack;

	while (temp)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		gval.exitflag = 1;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;

	temp->next = temp->next->next;
	temp->prev = *stack;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
}

/**
*@sub: substract two elemeny on the pot of the stack
*@stack_t: head of the stack
*@line_number: line_number
*@return: void
*/

void sub(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		gval.exitflag = 1;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n -= temp->n;
	free(temp);
}
/**
*@mydiv: divide two element on the top of the stack
*@stack_t: head of the stack
*@line_number: line_number
*@return: void
*/

void mydiv(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		gval.exitflag = 1;
		return;
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		gval.exitflag = 1;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n /= temp->n;
	free(temp);
}

/**
*@mymul: multiply two element on the top of the stack
*@stack_t: head of the stack
*@line_number: line_number
*@return:void
*/

void mymul(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		gval.exitflag = 1;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= temp->n;
	free(temp);
}
