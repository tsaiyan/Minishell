#include "header.h"

// add fd to close list

int	add_fd_to_close(t_bin *bin, int fd, int ret)
{
	int	i;

	i = 0;
	while (bin->fds_to_close[i])
		i++;
	if (fd > 0)
		bin->fds_to_close[i] = fd;
	return (ret);
}

// find pipes in argv

int	check_pipes(t_bin *bin)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (bin->argv[i])
	{
		if (!ft_strcmp(bin->argv[i], "|"))
			ret++;
		i++;
	}
	bin->p_count = ret;
	return (ret);
}

// открывает файл связанный с редиректом
// записывает фд по номеру команды
// добавляет фд в массив на закрытие

int	ft_write_red_fd_in_pipes(t_bin *bin, char *command, int i, int c)
{
	int	ret;

	ret = 0;
	if (!ft_strcmp(command, ">"))
	{
		ret = open(bin->argv[i + 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
		if (check_ret(bin, ret, bin->argv[i + 1]) == -1)
			return (-1);
		bin->fds_red[c][1] = ret;
	}
	if (!ft_strcmp(command, ">>"))
	{
		ret = open(bin->argv[i + 1], O_CREAT | O_RDWR | O_APPEND, 0666);
		if (check_ret(bin, ret, bin->argv[i + 1]) == -1)
			return (-1);
		bin->fds_red[c][1] = ret;
	}
	if (!ft_strcmp(command, "<"))
	{
		ret = open(bin->argv[i + 1], O_RDONLY);
		if (check_ret(bin, ret, bin->argv[i + 1]) == -1)
			return (-1);
		bin->fds_red[c][0] = ret;
	}
	return (add_fd_to_close(bin, ret, 1));
}

	// find redirect inside 1 pipe
	// open and creates files
	// writting fd in fd's array massive
	// del redirect and file from argv

int	find_write_and_delete_redirect(t_bin *bin, int i, int c)
{
	while (bin->argv[i] && ft_strcmp(bin->argv[i], "|"))
	{
		if (its_redirect(bin->argv[i]))
		{
			ft_write_red_fd_in_pipes(bin, bin->argv[i], i, c);
			bin->argv = ft_del_index_in2massive(bin->argv, i);
			if (bin->argv[i] && ft_strcmp(bin->argv[i], "|"))
				bin->argv = ft_del_index_in2massive(bin->argv, i);
			else
			{
				bin->error_ret = -1;
				return (ft_puts(" syntax error near unexpected token"));
			}
			i--;
		}
		i++;
	}
	return (0);
}

int	it_not_builtin(char *command)
{
	if (!ft_strcmp(command, "pwd") || !ft_strcmp(command, "echo") || \
	!ft_strcmp(command, "env") || \
	!ft_strcmp(command, "exit") || !ft_strcmp(command, "unset") || \
	!ft_strcmp(command, "export") || !ft_strcmp(command, "cd"))
		return (0);
	return (1);
}
