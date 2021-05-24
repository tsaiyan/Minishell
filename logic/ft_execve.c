#include "header.h"

char *get_excve_str(t_bin *bin, char *command, char **argv)
{
	char			*execve_str;
	int				ret;
	char			*dir_to_open = NULL;
	char			**split_str = NULL;
	struct dirent	*dir = NULL;
	int				flag = 1;
	int 			i = 0;
	DIR				*folder = NULL;
	char			*path = NULL;

	if (!command || !argv)
		return (NULL);
	if (command[ft_strlen(command) - 1] == '/')
	{
		folder = opendir(command);
		if (folder)
			dir = readdir(folder);
		if (command)
			command_error(command, 6);
		else
			command_error(command, 5);
		return (NULL);
	}
	// проверка на абсолютный путь
	if (argv[0][0] == '/' || argv[0][0] == '.')
		execve_str = ft_strdup(command);
	else
	{
		// достаем папки с коммандами из path
		path = ft_get_value(bin->export, "PATH");
		if (!path)
			return ((char*)command_error(command, 5));
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
			return(command_error(command, 1));
		execve_str = ft_strjoin(dir_to_open, command);
	}
	if (dir_to_open)
			free(dir_to_open);
	if (split_str)
		free_split(split_str);
	return (execve_str);
}

void	ft_execve(t_bin *bin, char *execve_str, char **argv)
{
	int	status;

	execve_str = get_excve_str(bin, argv[0], argv);
	if (execve_str)
		bin->pid = fork();
	if (bin->pid == 0)
	{
		g_sig.exit_status = execve(execve_str, argv, bin->envp);
		if (argv[0][0] == '.' || argv[0][0] == '/')
			exit(command_error(argv[0], 5));
		exit(0);
	}
	else
	{
		waitpid(bin->pid, &status, 0);
		ft_close_redifd(bin);
		if (execve_str)
			free(execve_str);
		if (status == 2)
			g_sig.exit_status = 130;
		else if (status == 3)
			g_sig.exit_status = 131;
		else if (status != 0 && status != 256)
			g_sig.exit_status = status >> 8;
	}
}
