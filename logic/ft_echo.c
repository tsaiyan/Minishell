#include "header.h"

static int check_n(char *str)
{
	int i;

	i = 2;
	if (!ft_strncmp(str, "-n", 2))
	{
		while (str[i] != 0)
		{
			if (str[i] !=0 && str[i] != 'n')
			{
				ft_putstr_fd(str, 1);
				return (2);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void ft_echo(char **argv)
{
	int flag;
	int fd;

	fd = 1;
	if (argv[1] == 0)
	{
		write(1, "\n\n", 2);
		return;
	}
	ft_putstr_fd("\n", 1);
	flag = check_n(argv[1]);
	if (flag == 2 && argv[2])
	{
		ft_putstr_fd(" ", fd);
		ft_putstr_fd(argv[2], fd);
		return;
	}
	else if (flag == 2)
		return;
	ft_putstr_fd(argv[1 + flag], fd);
	if (flag != 1)
		ft_putstr_fd("\n", fd);
}