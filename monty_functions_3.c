#include "monty.h"

/**
 * push - added element to stack
 *
 * Return: 0 at sucess, -1 fail.
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (!stack || !line_number)
	{
		return;
	}
}

/**
 * push - print all element of stack
 *
 * Return: No thing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	if (!stack || !line_number)
	{
		return;
	}
}

/**
 * pint - print last element of stack
 *
 * Return: No thing.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	print_int(2);
	_putchar('\n');
	if (!stack || !line_number)
	{
		return;
	}
}