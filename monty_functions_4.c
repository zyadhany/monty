#include "monty.h"

/**
 * add - added element to stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: 0 at sucess, -1 fail.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	info.command_count = line_number;
	info.stack = *stack;

	if (!info.top)
		CodeError("can't add, stack too short");
	if (!info.top->prev)
		CodeError("can't add, stack too short");

	info.top->prev->n += info.top->n;

	pop(stack, line_number);
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
