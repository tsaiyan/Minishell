#include "header.h"

void	ft_execve(t_bin *bin)
{
	pid_t			pid;
	int				ret;
	DIR				*folder;
	struct dirent	*command;
	char			**split_str = NULL;
	char			*str2;
	char			*dir_to_open = NULL;
	int				flag;
	int 			i;
	char			*execve_str;

	i = 0;
	flag = 1;
	command = NULL;
	ret = 1;

	ft_puts(NULL);
	if (bin->argv[0][0] == '/')
		execve_str = bin->argv[0];
	else
	{
		str2 = ft_get_value(bin->export, "PATH");
		split_str = ft_split(str2, ':');
		while (split_str[i] && flag)
		{
			if (dir_to_open)
				free(dir_to_open);
			dir_to_open = ft_strjoin(split_str[i], "/");
			folder = opendir(dir_to_open);
			while (folder && ret && flag)
			{
				command = readdir(folder);
				if (!command)
					ret = 0;
				if (command && !strcmp(command->d_name, bin->argv[0]))
					flag = 0;
			}
			ret = 1;
			if (folder)
				closedir(folder);
			i++;
		}
		if (!command)
		{
			command_error(bin->argv[0], 1);
			return;
		}
		execve_str = ft_strjoin(dir_to_open, bin->argv[0]);
	}
	pid = fork();
	if (pid == 0)
	{
		ret = execve(execve_str, bin->argv, bin->envp);
		if (ret == -1)
			exit(command_error(bin->argv[0], 1));
	}
	else
	{
		wait(NULL);
		if (dir_to_open)
			free(dir_to_open);
		if (split_str)
		free_split(split_str);
	}
}