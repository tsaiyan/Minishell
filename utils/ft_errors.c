#include "header.h"

static void prnt(char *arg)
{
	int 	i;

	i = -1;
	if (arg)
	{
		while (arg[++i] != 0)
		{
			if (arg[i] >= 0)
				write(1, &arg[i], 1);
		}
	}
}

int write_error(int code, char *arg)
{
	write(2, "minishell: ", 11);
	prnt(arg);
	if (code == MULTI_LINE_COMMAND)
		write(2, ": multi-line command\n", 21);
	if (code == CANT_ACCESS_ENVP)
		write(2, ": cant access envp\n", 19);
	return (code);
}

int ft_errors(int code)
{
	write(2, "minishell:", 10);
	strerror(errno);
	return (code);
}