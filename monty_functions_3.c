#include "monty.h"

/**
 * push - added element to stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: 0 at sucess, -1 fail.
 */
void push(stack_t **stack, unsigned int line_number)
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
 * pall - print all element of stack
 * @stack: given stack.
 * @line_number: current line.
 *
 * Return: No thing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	info.command_count = line_number;
	info.stack = *stack;

	print_end_dlistint(info.top);
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

	if (!info.top)
		CodeError("can't pint, stack empty");

	print_int(info.top->n);
	_putchar('\n');
}

/**
 * pop - pop last element of stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: No thing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	info.command_count = line_number;
	info.stack = *stack;

	if (!info.top)
		CodeError("can't pop an empty stack");

	tmp = info.top;
	info.top = info.top->prev;

	rem_node(tmp);
}

/**
 * swap - swap last two elements of stack
 * @stack: given stack.
 * @line_number: current line. *
 * Return: No thing.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int *tmp;

	info.command_count = line_number;
	info.stack = *stack;

	if (!info.top)
		CodeError("can't swap, stack too short");
	if (!info.top->prev)
		CodeError("can't swap, stack too short");

	tmp = info.top->n;
	info.top->n = info.top->prev->n;
	info.top->prev->n = tmp;
}

