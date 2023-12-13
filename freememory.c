#include "main.h"
/**
 * free_p - free the memory from buffer and array of arguments
 * @n:arguments number
 *
 * Return: void;
 */
void free_p(const unsigned int n, ...)
{
	va_list arglist;
	unsigned int i;
	char *arg;

	va_start(arglist, n);
	for (i = 0; i < n; i++)
	{
		arg = va_arg(arglist, char *);
		free(arg);
	}
}

/**
 * free_pointerArr - free the memory of pointer array
 * @arr: pointer array
 * Return: void
 */
void free_pointerArr(char **arr)
{
	free(arr);
}
