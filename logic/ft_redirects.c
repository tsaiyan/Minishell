#include "header.h"

int	find_redirects(t_bin *bin)
{
	int	i;

	i = -1;
	while (bin->envp && bin->argv[++i])
		if (bin->argv[i][0] == FRWRD_RDRCT || bin->argv[i][0] == RVRS_RDRCT)
			return (1);
	return (0);
}

int	check_ret(t_bin *bin, int ret, char *way)
{
	if (ret == -1)
	{
		command_error(way, 7);
		bin->error = 1;
		ft_close_redifd(bin);
		return (-1);
	}
	return (0);
}

int	ft_redopen(t_bin *bin, char *way, int flag, int index)
{
	int	ret;

	ret = 0;
	if (flag == 1)
	{
		if (bin->to)
			close(bin->to);
		ret = open(way, O_CREAT | O_RDWR | O_APPEND, 0666);
		if (check_ret(bin, ret, way) == -1)
			return (-1);
		bin->to = ret;
		bin->append = 1;
		bin->indx_to = index;
	}
	if (flag == 2)
	{
		if (bin->from)
			close(bin->from);
		ret = open(way, O_RDONLY);
		if (check_ret(bin, ret, way) == -1)
			return (-1);
		bin->from = ret;
		bin->indx_from = index;
	}
	return (1);
}

int	ft_redopen2(t_bin *bin, char *way, int flag, int index)
{
	int	ret;

	ret = 0;
	if (flag == 3)
	{
		if (bin->to)
			close(bin->to);
		ret = open(way, O_CREAT | O_RDWR | O_TRUNC, 0666);
		if (check_ret(bin, ret, way) == -1)
			return (-1);
		bin->to = ret;
		bin->append = 0;
		bin->indx_to = index;
	}
	return (1);
}

void	ft_redirects(t_bin *bin, char **argv)
{
	int	i;
	int	flag;

	i = -1;
	bin->del_pipes = 0;
	while (argv[++i])
	{
		flag = 0;
		if (!ft_strcmp(argv[i], "\005"))
			bin->del_pipes++;
		if (!ft_strcmp(argv[i], "\007\007"))
			flag = ft_redopen(bin, argv[i + 1], 1, i - 1);
		if (!ft_strcmp(argv[i], "\006"))
			flag = ft_redopen(bin, argv[i + 1], 2, i - 1);
		if (!ft_strcmp(argv[i], "\007"))
			flag = ft_redopen2(bin, argv[i + 1], 3, i - 1);
		if (flag)
		{
			argv = ft_del_index_in2massive(argv, i);
			if (argv[i])
				argv = ft_del_index_in2massive(argv, i);
			i--;
		}
	}
	bin->argv = argv;
}
