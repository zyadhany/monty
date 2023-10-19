#include "monty.h"

/**
 * main - Entry point
 * @argc: number of argument
 * @argv: array of argument
 * Description: Where all the shell action plays out
 * Return: 0 On success
 */
int main(int argc, char *argv[])
{
	set_info();
	info.argv = argv;
	info.argc = argc;

	signal(SIGINT, SIG_IGN);

	if (argc != 2)
	{
		_perror("USAGE: monty file\n");
		_exitS();
	}

	info.fn = fopen(argv[1], "r");

	if (!info.fn)
	{
		_perror("Error: Can't open file ");
		_perror(argv[1]);
		_perror("\n");
		_exitS();
	}

	do {
		monty();
		info.command_count++;
	} while (1);

	return (0);
}
