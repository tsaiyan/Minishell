#include "header.h"

int	ft_it_digit_array(char *argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			if (!ft_isdigit(argv[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

void	write_global_and_exit(int code)
{
	g_sig.exit_status = code;
	exit(code);
}

int	ft_exit(char **argv)
{
	int		i;
	int		j;

	i = 1;
	ft_puts("exit");
	if (!argv[1])
		write_global_and_exit(0);
	if (ft_it_digit_array(argv[1]) && argv[2])
	{
		g_sig.exit_status = 1;
		return (command_error(argv[i], 4));
	}
	while (argv[i])
	{
		j = 0;
		if (!ft_it_digit_array(argv[i]))
		{
			command_error(argv[i], 3);
			write_global_and_exit(255);
		}
		i++;
	}
	if (ft_atoi(argv[1]) >= 0 && ft_atoi(argv[1]) <= 255 && !argv[2])
		write_global_and_exit(ft_atoi(argv[1]));
	if ((ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > 255) && !argv[2])
		write_global_and_exit(255);
	return (0);
}
