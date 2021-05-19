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

	i = -1;
	while (bin->argv[++i])
	{
		free(bin->argv[i]);
	}
	free(bin->argv);
	bin->argv=NULL;
}

// MAIN FUNCTION

void			ft_buildins(t_bin *bin)
{	
	if (bin->to)
		dup2(bin->to, 1);
	if (bin->from)
		dup2(bin->from, 0);
	if (!ft_strcmp(bin->argv[0], "export"))
		ft_export(bin);
	else if (!ft_strcmp(bin->argv[0], "exit"))
		ft_exit(bin->argv);
	else if (!ft_strcmp(bin->argv[0], "cd") || !ft_strcmp(bin->argv[0], "CD"))
		ft_cd(bin);
	else if (!ft_strcmp(bin->argv[0], "unset"))
		ft_unset(bin);
	else if (!ft_strcmp(bin->argv[0], "echo") || !ft_strcmp(bin->argv[0], "ECHO"))
		ft_echo(bin);
	else if (!ft_strcmp(bin->argv[0], "pwd") || !ft_strcmp(bin->argv[0], "PWD"))
		ft_pwd(bin);
	else if (!ft_strcmp(bin->argv[0], "env") || !ft_strcmp(bin->argv[0], "ENV"))
		ft_env(bin);
	else if (!bin->p_count)
		ft_execve(bin, bin->argv[0], bin->argv);
	if (bin->to)
	{
		close(bin->to);
		dup2(bin->savefd1, 1);
		bin->to = 0;
	}
	if (bin->from)
	{	
		close(bin->from);
		dup2(bin->savefd0, 0);
		bin->from = 0;
	}
}

int 		parser(char **argv, char ***envp, t_bin *bin)
{
	if (!bin->exit_off)
		write (1, "\n", 1);
	bin->indx_from = -1;
	bin->indx_to = -1;
	if (!bin || !ft_strcmp(argv[0], "exit"))
		ft_exit(argv);
	bin->envp = *envp;
	bin->argv = argv;
	if (find_redirects(bin))
		ft_redirects(bin, bin->argv);
	bin->argc = ft_massive_len(bin->argv);
	if (!bin->export)
		bin->export = arr_to_dlist(bin->envp);
	if (!bin->envp_lst)
		bin->envp_lst = arr_to_dlist(bin->envp);
	if (bin->to)
		bin->savefd1 = dup(1);
	if (bin->from)
		bin->savefd0 = dup(0);
	if (check_pipes(bin))
		ft_pipes(bin);
	if (!bin->error)	
		ft_buildins(bin);
	*envp = bin->envp;
	free_parcer(bin);
	return (0);
}