#include "monty.h"

/**
 * add - added element to stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: 0 at sucess, -1 fail.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int n;

	info.command_count = line_number;

	n = _stoi(info.command[1]);
	if (n == info.MODE)
		CodeError("usage: push integer");

	info.top = add_dnodeint_end(stack, n);

	if (!info.top)
		MalocError();
}

/**
 * nop - print all element of stack
 * @stack: given stack.
 * @line_number: current line.
 *
 * Return: No thing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	info.command_count = line_number;
	info.stack = *stack;
}
