#include "main.h"

/**
 * prompt -  wait for the user to enter a command
 * @buffer: pointer to a buffer which contains the command
 *
 * Return: number of characters
 */
int prompt(char **buffer)
{
	ssize_t numbers_chars = 0;
	size_t n = 0;

	if (isatty(STDIN_FILENO) == 1)
		_printf("($) ");
	numbers_chars = getline(buffer, &n, stdin);

	return (numbers_chars);
}
