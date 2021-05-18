#include "header.h"

int		find_redirects(t_bin * bin)
{
	int i = -1;

	while (bin->argv[++i])
		if (bin->argv[i][0] == '>' || bin->argv[i][0] == '<')
			return(1);
	return(0);
}

// 1 - <, 2 - >, 3 - >>
// обработать ошибки

int		ft_redopen(t_bin *bin, char *way, int flag)
{
	int ret = 0;

	if (flag == 1)
	{
		if (bin->from)
			close(bin->from);
		ret = open(way, O_CREAT | O_WRONLY);
	}
	if (flag == 2)
	{
		if (bin->to)
			close(bin->to);
		ret = open(way, O_CREAT | O_TRUNC);
	}
	if (flag == 3)
	{
		if (bin->to)
			close(bin->to);
		ret = open(way, O_CREAT | O_APPEND);
	}
	if (ret == -1)
	{
		ft_puts("can't open the file");
		return(-1);
	}
	if (flag == 1)
		bin->from = ret;
	else
		bin->to = ret;
	return (1);
}

void	ft_redirects(t_bin *bin, char **argv)
{
	int i = 0;
	int flag;
	while (argv[i])
	{
		flag = 0;
		if	(!ft_strcmp(argv[i], ">>"))
			flag = ft_redopen(bin, argv[i], 3);
		if	(!ft_strcmp(argv[i], "<"))
			flag = ft_redopen(bin, argv[i], 2);
		if	(!ft_strcmp(argv[i], ">"))
			flag = ft_redopen(bin, argv[i], 1);
		if (flag)
		{
			argv = ft_del_index_in2massive(argv, i);
			if (argv[i])
				argv = ft_del_index_in2massive(argv, i);
			i--;
		}
		i++;
	}
	bin->argv = argv;
	write(1, "\n", 1);
	puts_2d(argv);
}