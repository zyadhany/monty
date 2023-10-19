#include "monty.h"

int set_info(void);
struct INFO info;

/**
 * set_info - set up info.
 *
 * Return: 0 at sucess, 1 fail.
 */
int set_info(void)
{
	int stats = 0;

	info.stack;
	info.command_count = 1;
	info.exit = 0;
	info.fn = info.argc = info.buffer_index = 0;
	info.status = EXIT_FAILURE;
	info.argv = info.command = NULL;
	info.commands_To_run = NULL;
	info.input = info.buffer = NULL;
	info.stack = NULL;

	stats += set_fuction();
	stats += set_buffer();

	if (stats < 0)
		_exitS();

	return (0);
}

/**
 * set_fuction - set fuctions into info
 *
 * Return: 0 at sucess, -1 fail.
 */
int set_fuction(void)
{
	info.functions[0].name = "push";
	info.functions[0].func = &push;

	info.functions[1].name = "pall";
	info.functions[1].func = &pall;

	info.functions[2].name = NULL;
	info.functions[2].func = NULL;

	return (0);
}

/**
 * set_buffer - set up buffer for memory mangment.
 *
 * Return: 0 at sucess, -1 fail.
 */
int set_buffer(void)
{
	info.buffer = malloc(sizeof(char) * (info.BUFFER_SIZE + 1));

	if (!info.buffer)
		MalocError();

	info.buffer[info.BUFFER_SIZE] = '\0';

	return (0);
}

/**
 * FreeInfo - free all alocated memory in info.
 *
 */
void FreeInfo(void)
{
	close(info.fn);
	free(info.input);
	free(info.buffer);
	freeString(info.command);
}

/**
 * _exitS - exit code on error
 * Return: Nothing
 */
void _exitS(void)
{
	FreeInfo();
	exit(info.status);
}
