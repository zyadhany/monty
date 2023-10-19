#include "monty.h"

/**
 * push - added element to stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: 0 at sucess, -1 fail.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, err = 0;

	info.command_count = line_number;

	n = _stoi(info.command[1]);
	if (n == info.MODE)
		err = 1;

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
