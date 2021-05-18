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
}

void	ft_redirects(t_bin *bin, char **argv)
{
	int i = 0;
	while (argv[i])
	{
		if	(ft_strcmp(argv[i], "<<"))
			ft_redopen(bin, argv[i], 3);
		if	(ft_strcmp(argv[i], "<"))
			ft_redopen(bin, argv[i], 2);
		if	(ft_strcmp(argv[i], ">"))
			ft_redopen(bin, argv[i], 1);	

	}
}