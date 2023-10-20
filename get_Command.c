#include "monty.h"

/**
 * get_input - gets input from user
 * Return: 0 on sucess, -1 on failure
 */
int get_input(void)
{
	int n, len;

	n = _getline(&info.input, &len, info.fn);

	if (n == -1)
		_exitS();

	return (0);
}


/**
 * break_command - break command into several commands
 * Return: 0 at sucess, -1 fail
 */
int break_command(void)
{
	char dlm[3] = " \n\0";

	if (!_strcnt(info.input, dlm))
		return (-1);

	info.command = _strtok(info.input, dlm);
	if (!info.command)
		MalocError();

	return (0);
}

/**
 * get_Command - gets input from user
 * and separates it into several commands
 * or Command and flags/arguments
 * Return: array of strings
 */
int get_Command(void)
{
	get_input();
	break_command();

	return (0);
}
