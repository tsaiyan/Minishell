#include "header.h"
#include "built_in_header.h"

int	ft_check_n(t_bin *bin)
{
	int i;
	int j;
	i = 1;
	j = 2;
	while (bin->argv[i])
	{
		if (!ft_strncmp(bin->argv[i], "-n", 2))
		{
			while (bin->argv[i][j])
			{
				if (bin->argv[i][j] != 'n' && bin->argv[i][j] != '\0' && bin->argv[i][j] != ' ')
					return(i);
				j++;
			}
			bin->n_flag = 1;
		}
		i++;
		j = 2;
	}
	return(i - 1);
}

void ft_echo(char **argv)
{
	t_bin *bin;
	int move;
	int fd;

	fd = 1;
	move = 1;
	write(1,"\n", 1);
	if (argv[1] == 0)
	{
		write(1,"\n", 1);
		return;
	}
	bin = malloc(sizeof(t_bin));
	bin->argv = argv;
	bin->n_flag = 0;
//	if (!bin)
//		ft_exit;
	move = ft_check_n(bin);
	if (!argv[2] && bin->n_flag)
		return;
	while(argv[move])
	{
		ft_putstr_fd(argv[move++], fd);
		if (argv[move])
		ft_putchar_fd(' ', fd);
	}
	if (!bin->n_flag)
		ft_putchar_fd('\n', fd);
}