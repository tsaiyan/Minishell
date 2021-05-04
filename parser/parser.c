#include "header.h"

// func for null struct
// static int ft_putin(t_bin *bin)
// {
// 	bin->n_flag = 0;
// 	bin->argc = 0;
// 	//bin->ar_export = NULL;
// }

// очистка ARGV перед выходом из функции

static void free_parcer(t_bin *bin)
{
	int i;

	i = 0;
	while (bin->argv[i])
	{
		free(bin->argv[i++]);
	}
	free(bin->argv);
	bin->argv=NULL;
}

void command_error(char *command, char *str)
{
			ft_putstr("\nbash: ");
			ft_putstr(command);
			ft_puts(str);
}
// MAIN FUNCTION

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
		command_error(argv[0], ": command not found");
	free_parcer(bin);
	return (0);
}