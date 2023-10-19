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

	info.fn = open(argv[1], O_RDONLY);

	if (info.fn == -1) {
        _perror("Error: Can't open file ");
        _perror(argv[1]);
        _perror("\n");
		_exitS();
    }

	FreeInfo();
	return (0);
}
