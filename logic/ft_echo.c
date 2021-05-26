#include "header.h"

static int	ft_check_n_ret(t_bin *bin, int ret)
{
	if (bin->n_flag)
		return (ret);
	else
		return (1);
}

static int	ft_check_n(t_bin *bin, char **argv)
{
	int	i;
	int	j;
	int	ret;

	i = 1;
	j = 2;
	ret = 0;

	if (!ft_strncmp(argv[i], "-n", 2))
		while (argv[i])
		{
			if (!ft_strncmp(argv[i], "-n", 2))
			{
				while (argv[i][j])
				{
					if (argv[i][j] != 'n' && argv[i][j] && argv[i][j] != ' ')
						return (i);
					j++;
				}
				bin->n_flag = 1;
				ret = i + 1;
			}
			i++;
			j = 2;
		}
	return (ft_check_n_ret(bin, ret));
}

void	ft_echo(t_bin *bin, char **argv)
{
	int		move;

	move = 1;
	if (argv[1] == NULL)
	{
		ft_putchar('\n');
		return ;
	}
	move = ft_check_n(bin, argv);
	if (!argv[2] && bin->n_flag)
		return ;
	if (move == 0)
		move++;
	while (argv[move])
	{
		ft_putstr(argv[move]);
		move++;
		if (argv[move])
			ft_putchar(' ');
	}
	if (!bin->n_flag)
		ft_putchar('\n');
	g_sig.exit_status = 0;
}
