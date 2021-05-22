#include "header.h"

int	command_error2(char *command, int flag)
{
	if (flag == 5)
	{
		ft_putstr("bash: ");
		ft_putstr(command);
		ft_puts(": No such file or directory");
	}
	if (flag == 6)
	{
		ft_putstr("bash: ");
		ft_putstr(command);
		ft_puts(": is a directory");
		return (126);
	}
	return (127);
}

int	command_error(char *command, int flag)
{
	if (flag == 1)
	{
		ft_putstr("bash: ");
		ft_putstr(command);
		ft_puts(": command not found");
	}
	else if (flag == 2)
	{
		ft_putstr("bash: export: '");
		ft_putstr(command);
		ft_putstr("': not a valid identifier\n");
	}
	else if (flag == 3)
	{
		ft_puts("\nexit");
		ft_putstr("bash: exit ");
		ft_putstr(command);
		ft_puts(": numeric argument required");
	}
	else if (flag == 4)
		ft_puts("\nexit\nbash: exit: too many arguments");
	else
		return (command_error2(command, flag));
	return (127);
}

int	its_redirect(char *str)
{
	if (!ft_strcmp(str, ">") || !ft_strcmp(str, ">>") || \
	!ft_strcmp(str, "<"))
		return (1);
	return (0);
}