#include "monty.h"

/**
 * execute_Command - executes a given command
 * Return: On success, 0.
 * On error, 1.
 */
int execute_Command(void)
{
	unsigned int i;

	for (i = 0; info.functions[i].opcode; i++)
		if (_strcomp(info.command[0], info.functions[i].opcode) == 0){
			info.functions[i].f(&info.stack, i);
			return (0);
		}

	_perror("L");
	_perror(int_to_string(info.command_count));
	_perror(": unknown instruction ");
	_perror(info.command[0]);
	_perror("\n");
	info.exit = EXIT_FAILURE;
	_exitS();
	return (EXIT_FAILURE);
}
