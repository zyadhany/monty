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

	info.command_count = 1;
	info.exit = 0;
	info.fn = info.argc = info.buffer_index = 0;
	info.status = EXIT_FAILURE;
	info.argv = info.command = NULL;
	info.commands_To_run = NULL;
	info.input = info.buffer = NULL;
	info.stack = info.top = NULL;
	info.MODE = 175443913;

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
	info.functions[0].opcode = "push";
	info.functions[0].f = &push;

	info.functions[1].opcode = "pall";
	info.functions[1].f = &pall;

	info.functions[2].opcode = "pint";
	info.functions[2].f = &pint;

	info.functions[3].opcode = "pop";
	info.functions[3].f = &pop;

	info.functions[4].opcode = "swap";
	info.functions[4].f = &swap;

	info.functions[5].opcode = "nop";
	info.functions[5].f = &nop;

	info.functions[6].opcode = "add";
	info.functions[6].f = &_add;

	info.functions[7].opcode = "sub";
	info.functions[7].f = &_sub;

	info.functions[8].opcode = "div";
	info.functions[8].f = &_div;

	info.functions[9].opcode = "mul";
	info.functions[9].f = &_mul;

	info.functions[10].opcode = "mod";
	info.functions[10].f = &_mod;

	info.functions[11].opcode = NULL;
	info.functions[11].f = NULL;
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
	free_dlistint(info.stack);
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
