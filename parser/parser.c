#include "header.h"

int 		parser(char **argv, char **envp)
{
	t_bin *bin;

	bin = malloc(sizeof(t_bin));
	if (!bin)
		return(-1);
	bin->n_flag = 0;
	bin->envp = envp;
	bin->argv = argv;
	if (!ft_strcmp(argv[0], "echo"))
		ft_echo(bin);
	else if (!ft_strcmp(argv[0], "pwd"))
		ft_pwd(bin);
	else if (!ft_strcmp(argv[0], "env"))
		ft_env(bin);
	else
	{
		ft_putstr("\nbash: ");
		ft_putstr(argv[0]);
		ft_puts(": command not found");
	}
}