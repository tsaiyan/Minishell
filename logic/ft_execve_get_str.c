#include "header.h"

char	*ret_get_excve_str(t_bin *bin)
{
	if (bin->dir_to_open)
		free(bin->dir_to_open);
	if (bin->split_str)
		free_split(bin->split_str);
	return (bin->execve_str);
}

int	make_path_str(t_bin *bin, char *command)
{
	bin->path = ft_get_value(bin->export, "PATH");
	if (!bin->path)
	{
		command_error(command, 5);
		return (-1);
	}
	bin->split_str = ft_split(bin->path, ':');
	return (0);
}

void	free_and_write_get_execve_str(t_bin *bin, int i)
{
	if (bin->dir_to_open)
		free(bin->dir_to_open);
	bin->dir_to_open = ft_strjoin(bin->split_str[i], "/");
	bin->folder = opendir(bin->dir_to_open);
}
