#include "header.h"

static void	prnt(char *arg)
{
	int	i;

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

static int	write_error2(int code)
{
	if (code == ERROR_UNEXPECTED_SEMICOLON)
	{
		write(2, "syntax error near unexpected token `;'\n", 39);
		return (code);
	}
	if (code == ERROR_UNEXPECTED_PIPE)
	{
		write(2, "syntax error near unexpected token `|'\n", 39);
		return (code);
	}
	if (code == SYNTAX_ERROR_PREPARS)
	{
		write(2, "syntax error\n", 13);
		return (code);
	}
	if (code == TERM_ERRORS)
	{
		write(2, "TERMCAP ERROR\n", 14);
		return (code);
	}
	return (1);
}

int	write_error(int code, char *arg)
{
	write(2, "\nminishell: ", 12);
	if (0 > write_error2(code))
		return (code);
	prnt(arg);
	if (code == MULTI_LINE_COMMAND)
		write(2, ": multi-line command\n", 21);
	if (code == CANT_ACCESS_ENVP)
		write(2, ": cant access envp\n", 19);
	if (code == SYNTAX_ERROR)
		write(2, ": syntax error\n", 15);
	return (code);
}

int	ft_errors(int code)
{
	write(2, "minishell:", 10);
	printf("%s\n", strerror(errno));
	return (code);
}
