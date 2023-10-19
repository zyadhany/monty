#include "monty.h"

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
