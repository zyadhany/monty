#include "monty.h"

/**
 * _add - added element to stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: 0 at sucess, -1 fail.
 */
void _add(stack_t **stack, unsigned int line_number)
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
 * _sub - added element to stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: 0 at sucess, -1 fail.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	info.command_count = line_number;
	info.stack = *stack;

	if (!info.top)
		CodeError("can't add, stack too short");
	if (!info.top->prev)
		CodeError("can't add, stack too short");

	info.top->prev->n -= info.top->n;

	pop(stack, line_number);
}

/**
 * _div - added element to stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: 0 at sucess, -1 fail.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	info.command_count = line_number;
	info.stack = *stack;

	if (!info.top)
		CodeError("can't add, stack too short");
	if (!info.top->prev)
		CodeError("can't add, stack too short");

	info.top->prev->n /= info.top->n;

	pop(stack, line_number);
}

/**
 * _mul - added element to stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: 0 at sucess, -1 fail.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	info.command_count = line_number;
	info.stack = *stack;

	if (!info.top)
		CodeError("can't add, stack too short");
	if (!info.top->prev)
		CodeError("can't add, stack too short");

	info.top->prev->n *= info.top->n;

	pop(stack, line_number);
}

/**
 * _mod - added element to stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: 0 at sucess, -1 fail.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	info.command_count = line_number;
	info.stack = *stack;

	if (!info.top)
		CodeError("can't add, stack too short");
	if (!info.top->prev)
		CodeError("can't add, stack too short");

	info.top->prev->n %= info.top->n;

	pop(stack, line_number);
}
