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

void command_error(char *command, int flag)
{
	if (flag == 1)
	{
		ft_putstr("bash: ");
		ft_putstr(command);
		ft_puts(": command not found");
	}
	if (flag == 2)
	{
		ft_putstr("\nbash: export: '");
		ft_putstr(command);
		ft_putstr("': not a valid identifier");
	}
	if (flag == 3)
	{
		ft_puts("\nexit");
		ft_putstr("bash: exit ");
		ft_putstr(command);
		ft_puts(": numeric argument required");
	}
	if (flag == 4)
		ft_puts("\nexit\nbash: exit: too many arguments");
}
// MAIN FUNCTION

int 		parser(char **argv, char ***envp, t_bin *bin)
{
	bin->envp = *envp;
	bin->argv = argv;
	bin->argc = ft_strlen(argv);
	if (!bin->export)
		bin->export = arr_to_dlist(bin->envp);
	if (!bin->envp_lst)
		bin->envp_lst = arr_to_dlist(bin->envp);
	if (!ft_strcmp(argv[0], "echo") || !ft_strcmp(argv[0], "ECHO"))
		ft_echo(bin);
	else if (!ft_strcmp(argv[0], "pwd") || !ft_strcmp(argv[0], "PWD"))
		ft_pwd(bin);
	else if (!ft_strcmp(argv[0], "env") || !ft_strcmp(argv[0], "ENV"))
		ft_env(bin);
	else if (!ft_strcmp(argv[0], "export"))
		ft_export(bin);
	else if (!ft_strcmp(argv[0], "exit"))
		ft_exit(bin);
	else if (!ft_strcmp(argv[0], "cd") || !ft_strcmp(argv[0], "CD"))
		ft_cd(bin);
	else if (!ft_strcmp(argv[0], "unset"))
		ft_unset(bin);
	else
		ft_execve(bin);
		//command_error(argv[0], 1);
	*envp = bin->envp;
	free_parcer(bin);
	return (0);
}