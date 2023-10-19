#include "monty.h"

/**
 * MalocError - exit with erorr massage if can't get more memmory
 *
 * Return: Nothing.
 */
void MalocError(void)
{
	_perror("Error: malloc failed\n");
	info.exit = EXIT_FAILURE;
	_exitS();
}
