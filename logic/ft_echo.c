#include "header.h"

static void puts_echo(char **argv, int endn, int fd)
{
	int i;

	i = 1;

	while(argv[i])
	{
		ft_putstr_fd(argv[i], fd);
		argv[i++];
		if (argv[i])
			ft_putchar_fd(32, fd);
	}
	if (endn)
		ft_putchar_fd('\n', fd);
}

static int check_n(char **argv, int fd)
{
	int i;
	char *str;

	str = argv[1];
	i = 2;
	if (!ft_strncmp(str, "-n", 2))
	{
		while (str[i] != 0)
		{
			if (str[i] !=0 && str[i] != 'n')
			{
				puts_echo(argv, 1, fd);
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
	int i;

	i = 0;
	fd = 1;
	if (argv[1] == 0)
	{
		write(1, "\n\n", 2);
		return;
	}
	ft_putstr_fd("\n", 1);
	flag = check_n(argv, fd);
	if (flag == 2)
		return;
	i = flag;
	while(argv[1 + flag])
	{
		ft_putstr_fd(argv[1 + flag++], fd);
		if (argv[1 + flag])
			ft_putstr_fd(" ", fd);
	}
	if (i != 1)
		ft_putstr_fd("\n", fd);
}