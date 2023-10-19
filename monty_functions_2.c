#include "monty.h"

/**
 * MalocError - exit with erorr massage if can't get more memmory
 *
 * Return: Nothing.
 */
void MalocError(void)
{
	_perror("Error: malloc failed\n");
	info.status = EXIT_FAILURE;
	_exitS();
}

/**
 * CodeError - exit with erorr massage if got error in code.
 * @str: error to print.
 *
 * Return: Nothing.
 */
void CodeError(char *str)
{
	_perror("L");
	_perror(int_to_string(info.command_count));
	_perror(": ");
	_perror(str);
	_perror("\n");
	info.status = EXIT_FAILURE;
	_exitS();
}
