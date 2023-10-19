#include "monty.h"

/**
 * monty - carries out monty command operations
 * Description: This function feeds main
 * Return: On success, 0
 * On error, -1. errno is set appropriately
 */
int monty(void)
{
	info.command = NULL;

	get_Command();

	if (!info.command)
		return (0);

	info.status = execute_Command();

	freeString(info.command);
	return (0);
}
