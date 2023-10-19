#include "monty.h"

/**
 * push - added element to stack
 *
 * Return: 0 at sucess, -1 fail.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, err = 0;

	info.command_count = line_number;

	if (!info.command[1])
		err = 1;
	else
	{
		n = atoi(info.command[1]);
		if (n == 0 && (_strlen(info.command[1]) != 1 || info.command[1][0] != '0'))
			err = 1;
	}

	if (err)
		CodeError("usage: push integer");

	add_dnodeint_end(stack, n);
}

/**
 * push - print all element of stack
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
 *
 * Return: No thing.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	info.stack = *stack;
	info.command_count = line_number;
}