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
	int j;

	j = 1;
	str = argv[1];
	i = 2;
	while(argv[j])
	{
		if (!ft_strncmp(str, "-n", 2))
		{
			while (str[i] != 0)
			{
				if (str[i] !=0 && str[i] != 'n')
				{
					puts_echo(argv, 1, fd);
					return (-1);
				}
				i++;
			}
		}
		i = 2;
		j++;
	}
	return (--j);
}

void ft_echo2(char **argv)
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
	if (flag == -1)
		return;
	i = flag;
	while(argv[flag])
	{
		ft_putstr_fd(argv[flag++], fd);
		if (argv[flag])
			ft_putstr_fd(" ", fd);
	}
	if (i)
		ft_putstr_fd("\n", fd);
}