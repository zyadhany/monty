#include "monty.h"

/**
 * execute_Command - executes a given command
 * Return: On success, 0.
 * On error, 1.
 */
int execute_Command(void)
{
	int i;

	for (i = 0; info.functions[i].name; i++)
		if (_strcomp(info.command[0], info.functions[i].name) == 0)
			return (info.functions[i].func());

	_perror("L");
	_perror(int_to_string(info.command_count));
	_perror(": unknown instruction ");
	_perror(info.command[0]);
	_perror("\n");
	info.exit = EXIT_FAILURE;
	_exitS();
	return (EXIT_FAILURE);
}
