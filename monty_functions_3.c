#include "monty.h"

/**
 * push - added element to stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: 0 at sucess, -1 fail.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, i, err = 0;

	info.command_count = line_number;

	if (!info.command[1])
		err = 1;
	else
	{
		for (i = (info.command[1][0] == '-'); info.command[1][i]; i++)
			if (info.command[1][i] < '0' || info.command[1][i] > '9')
				err = 1;
		n = atoi(info.command[1]);
	}

	if (err)
		CodeError("usage: push integer");

	add_dnodeint_end(stack, n);
}

/**
 * pall - print all element of stack
 * @stack: given stack.
 * @line_number: current line.
 *
 * Return: No thing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	info.command_count = line_number;


	print_end_dlistint(*stack);
}

/**
 * pint - print last element of stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: No thing.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	info.stack = *stack;
	info.command_count = line_number;
}
