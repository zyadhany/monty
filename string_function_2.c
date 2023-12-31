#include "monty.h"


/**
 * _strcpy - copies specified string into another
 * @str1: string to copy to
 * @str2: string to copy from
 * Return: 0 on sucess -1 on failure
 */
int _strcpy(char **str1, char *str2)
{
	int n, i;

	n = _strlen(str2);

	if (!str1)
		return (-1);

	if (*str1 == str2)
		return (0);

	free(*str1);
	*str1 = malloc(sizeof(char) * (n + 1));

	if (!(*str1))
		return (-1);

	for (i = 0; i < n; i++)
		(*str1)[i] = str2[i];

	(*str1)[n] = '\0';
	return (0);
}

/**
 * _lcp - computes the longest common prefix between 2 strings
 * @str1: first string to consider
 * @str2: second string to consider
 * Return: integer equivalent of lcp
 */
int _lcp(char *str1, char *str2)
{
	int n = 0, i;

	if (!str1 || !str2)
		return (0);

	for (i = 0; str1[i] && str2[i]; i++)
	{
		if (str1[i] != str2[i])
			break;
		n++;
	}

	return (n);
}

/**
 * _appendStr - appends string to the end of another
 * @str1: string append to
 * @str2: string to append
 * Return: Nothing
 */
void _appendStr(char **str1, char *str2)
{
	int n, m, i;
	char *s;

	if (!str1 || !str2)
		return;

	n = _strlen(*str1);
	m = _strlen(str2);
	s = malloc(sizeof(char) * (n + m + 1));

	if (!s)
		MalocError();

	for (i = 0; i < n; i++)
		s[i] = (*str1)[i];

	for (i = n; i < n + m; i++)
		s[i] = str2[i - n];

	s[n + m] = '\0';

	free(*str1);
	*str1 = s;
}

/**
 * _strcomp - compares two strings
 * @str1: first string to consider
 * @str2: second string to consider
 * Return: 0 if equal, 1 if first is bigger, -1 otherwise
 */
int _strcomp(char *str1, char *str2)
{
	int n, m, i;

	n = _strlen(str1),
	m = _strlen(str2);

	for (i = 0; i < n && i < m; i++)
		if (str1[i] != str2[i])
			return ((str1[i] > str2[i]) * 2 - 1);

	if (n == m)
		return (0);

	return ((n > m) * 2 - 1);
}


/**
 * _reverse - reverses a given string
 * @s: string to reverse
 */
void _reverse(char *s)
{
	int n, i, tmp;

	n = _strlen(s);

	for (i = 0; i < n / 2; i++)
	{
		tmp = s[i];
		s[i] = s[n - 1 - i];
		s[n - 1 - i] = tmp;
	}
}
