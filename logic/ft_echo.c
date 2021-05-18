#include "header.h"

static int	 ft_check_n(t_bin *bin)
{
	int i;
	int j;
	int ret;

	i = 1;
	j = 2;
	while (bin->argv[i])
	{
		if (!ft_strncmp(bin->argv[i], "-n", 2))
		{
			while (bin->argv[i][j])
			{
				if (bin->argv[i][j] != 'n' && bin->argv[i][j] && bin->argv[i][j] != ' ')
					return(i);
				j++;
			}
			bin->n_flag = 1;
			ret = i + 1;
		}
		i++;
		j = 2;
	}
	if (bin -> n_flag)
		return(ret);
	else
		return(1);
}


void ft_echo(t_bin *bin)
{
	int		move;
	char	**argv;

	argv = bin->argv;
	move = 1;
	ft_putchar('\n');
	if (argv[1] == 0)
	{
		ft_putchar('\n');
		return;
	}
	move = ft_check_n(bin);
	if (!argv[2] && bin->n_flag)
		return;
	while(argv[move])
	{
		ft_putstr(argv[move]);
		move++;
		if (argv[move])
			ft_putchar(' ');
	}
	if (!bin->n_flag)
		ft_putchar('\n');
}