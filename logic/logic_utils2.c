#include "header.h"

void	command_error2(char *command, int flag)
{
	if (flag == 5)
	{
		printf("bash: %s : No such file or directory\n", command);
		g_sig.exit_status = 127;
	}
	if (flag == 6)
	{
		printf("bash: %s: is a directory\n", command);
		g_sig.exit_status = 126;
	}
		if (flag == 7)
	{
		printf("bash: %s : No such file or directory\n", command);
		g_sig.exit_status = 1;
	}
}

int	command_error(char *command, int flag)
{
	int save_fd;

	save_fd = dup(1);
	dup2(2, 1);
	if (flag == 1)
	{
		printf("bash: %s: command not found\n", command);
		g_sig.exit_status = 127;
	}
	else if (flag == 2)
		printf("bash: export: '%s: not a valid identifier\n", command);
	else if (flag == 3)
		printf("bash: exit %s: numeric argument required\n", command);
	else if (flag == 4)
		ft_puts("bash: exit: too many arguments");
	else
		command_error2(command, flag);
	if (flag != 1 && flag < 5)
		g_sig.exit_status = 1;
	dup2(save_fd, 1);
	return (0);
}

int	its_redirect(char *str)
{
	if (!ft_strcmp(str, "\007") || !ft_strcmp(str, "\007\007") || \
	!ft_strcmp(str, "\006"))
		return (1);
	return (0);
}

void	free_diropen(t_bin *bin)
{
	if (bin->dir_to_open)
		free(bin->dir_to_open);
	bin->dir_to_open = NULL;
}

void	excve_exit_errno(char *execve_str)
{
	 DIR	*folder;

	if (execve_str[0] == '.')
	{
		folder = opendir(execve_str);
		if (folder)
		{
			closedir(folder);
			command_error(execve_str, 6);
			exit(126);
		}
		else
		{
			command_error(execve_str, 5);
			exit(127);
		}
	}
}
