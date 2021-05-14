#include "header.h"

void	ft_execve(t_bin *bin, char *command, char **argv)
{
	
	int				ret;
	DIR				*folder = NULL;
	struct dirent	*dir = NULL;
	char			**split_str = NULL;
	char			*path = NULL;
	char			*dir_to_open = NULL;
	int				flag;
	int 			i;
	char			*execve_str = NULL;

	i = 0;
	flag = 1;
	ret = 1;

	write(1, "\n", 1);

	// проверка на папку
	if (command[ft_strlen(command) - 1] == '/')
	{
		folder = opendir(command);
		if (folder)
			dir = readdir(folder);
		if (command)
			command_error(command, 6);
		else
			command_error(command, 5);
		return;
	}
	// проверка на абсолютный путь
	if (argv[0][0] == '/' || argv[0][0] == '.')
		execve_str = command;
	else
	{
		// достаем папки с коммандами из path
		path = ft_get_value(bin->export, "PATH");
		if (!path)
		{
			command_error(command, 5);
			return;
		}
		split_str = ft_split(path, ':');
		while (split_str[i] && flag)
		{
			if (dir_to_open)
				free(dir_to_open);
			dir_to_open = ft_strjoin(split_str[i], "/");
			folder = opendir(dir_to_open);
			while (folder && ret && flag)
			{
				dir = readdir(folder);
				if (!dir)
					ret = 0;
				if (dir && !strcmp(dir->d_name, command))
					flag = 0;
			}
			ret = 1;
			if (folder)
				closedir(folder);
			i++;
		}
		if (!dir)
		{
			command_error(command, 1);
			return;
		}
		execve_str = ft_strjoin(dir_to_open, command);
	}
	//folder = opendir(argv[0]);
	// for pipes

	// делает пид если нет пайпов
	if (bin->p_count == 0)
		bin->pid = fork();
	if (bin->pid == 0)
	{
		ret = execve(execve_str, argv, bin->envp);
		if (argv[0][0] == '.')
			exit(command_error(command, 5));
		else
			exit(command_error(command, 1));
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