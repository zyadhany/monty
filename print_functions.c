#include "monty.h"

/**
 * _putchar - prints character to stdout
 * @c: char to be print
 * Return: 1 on success , -1 on failure
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _puts - prints an input string.
 * @str: the string to be printed.
 * Return: Nothing.
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
		_putchar(str[i++]);
}

/**
 * _perror - prints an input string to std error.
 * @str: the string to be printed.
 * Return: Nothing.
 */
void _perror(char *str)
{
	if (!str)
		return;

	write(STDERR_FILENO, str, _strlen(str));
}

/**
 * print_int - prints an integer
 * @n: integer to print
 */
void print_int(int n)
{
	_puts(int_to_string(n));
}

/**
 * _getline - gets input from user
 * @lineptr: line of input to get
 * @len: byte size of lineptr
 * @fd: file descriptor
 * Return: total bytes of input read
*/
int _getline(char **lineptr, int *len, int fd)
{
	int n = 0, bytesRead = 0;
	char c, prev = '#';

	if (!lineptr || !len || fd < 0)
		return (-1);

	info.buffer_index = 0;
	free(*lineptr);
	*lineptr = NULL;

	do {
		bytesRead = read(fd, info.buffer + info.buffer_index, 1);
		c = info.buffer[info.buffer_index];

		if (!bytesRead)
			break;
		if (bytesRead == -1)
			return (-1);
		info.buffer_index++;
		n++;
		if (c == '\n' || c == -1)
			break;
		if (c == prev && c == ' ')
			info.buffer_index--;
		prev = c;
		if (info.buffer_index == info.BUFFER_SIZE)
		{
			_appendStr(lineptr, info.buffer);
			info.buffer_index = 0;
		}
	} while (bytesRead);

	info.buffer[info.buffer_index] = '\0';
	_appendStr(lineptr, info.buffer);

	if (n == 0)
		return (-1);

	return (n);
}
