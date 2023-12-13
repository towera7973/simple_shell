#include "main.h"
/**
 * shell_loop - shell program
 * @argv: name of executable
 * @count: counter
 * Return: 0
 */
int shell_loop(char **argv, int count)
{
	char *buff = NULL, **av = NULL;
	ssize_t runcomm;

	if (prompt(&buff) == -1)
	{
		free_p(1, buff);
		return (1);
	}
	av = fillarguments(buff, " \t"), count++;
	if (av[0] == NULL)
	{
		free_p(1, buff), free_pointerArr(av);
		return (0);
	}
	if (av[0][0] != '/' && av[0][0] != '.')
	{
		runcomm = Builtins(av, buff, count);
		if (runcomm == 0 || runcomm == 2)
		{
			free_p(1, buff), free_pointerArr(av), runcomm == 0 ? (runcomm = 0) : (runcomm = 1);
			return (runcomm);
		}
		if (!(if_cmd_in_path(av)))
		{
			printerror(argv, count, av), free_p(1, buff), free_pointerArr(av);
			return (2);
		}
		else
		{
			processus(argv, av, buff, count), free_p(2, *av, buff), free_pointerArr(av);
			return (0);
		}
	}
	if (processus(argv, av, buff, count) != 0)
	{
		free_p(1, buff), free_pointerArr(av);
		return (2);
	}
	free_p(1, buff), free_pointerArr(av);
	return (0);
}
