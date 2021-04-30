#include "header.h"

// func for null struct
static int ft_putin(t_bin *bin)
{
	bin->n_flag = 0;
	bin->argc = 0;
	//bin->ar_export = NULL;
}

int 		parser(char **argv, char **envp, t_bin *bin)
{
	bin->envp = envp;
	bin->argv = argv;
	bin->argc = ft_strlen(argv);
	if (!ft_strcmp(argv[0], "echo"))
		ft_echo(bin);
	else if (!ft_strcmp(argv[0], "pwd"))
		ft_pwd(bin);
	else if (!ft_strcmp(argv[0], "env"))
		ft_env(bin);
	else if (!ft_strcmp(argv[0], "export"))
		ft_export(bin);
	else if (!ft_strcmp(argv[0], "exit"))
		exit(0);
	else
	{
		ft_putstr("\nbash: ");
		ft_putstr(argv[0]);
		ft_puts(": command not found");
	}
}