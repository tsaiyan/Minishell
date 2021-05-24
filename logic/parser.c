#include "header.h"

static void	end_of_parcer(t_bin *bin)
{
	int i;

	i = -1;
	while (bin->argv[++i])
	{
		free(bin->argv[i]);
	}
	free(bin->argv);
	bin->argv=NULL;
	i = -1;
	while (bin->fds_to_close[++i])
		close(bin->fds_to_close[i]);
	ft_bzero(bin->fds_to_close, i);
}

void	ft_close_redifd(t_bin * bin)
{
	if (bin->to > 0)
	{
		close(bin->to);
		dup2(bin->savefd1, 1);
		bin->to = 0;
	}
	if (bin->from > 0)
	{	
		close(bin->from);
		dup2(bin->savefd0, 0);
		bin->from = 0;
	}
}

// run buldins with redirects fd swap

void	ft_buildins(t_bin *bin)
{	
	if (bin->to)
		dup2(bin->to, 1);
	if (bin->from)
		dup2(bin->from, 0);
	if (!ft_strcmp(bin->argv[0], "export"))
		ft_export(bin, bin->argv);
	else if (!ft_strcmp(bin->argv[0], "exit"))
		ft_exit(bin->argv);
	else if (!ft_strcmp(bin->argv[0], "cd") || !ft_strcmp(bin->argv[0], "CD"))
		ft_cd(bin,  bin->argv);
	else if (!ft_strcmp(bin->argv[0], "unset"))
		ft_unset(bin, bin->argv);
	else if (!ft_strcmp(bin->argv[0], "echo") || !ft_strcmp(bin->argv[0], "ECHO"))
		ft_echo(bin, bin->argv);
	else if (!ft_strcmp(bin->argv[0], "pwd") || !ft_strcmp(bin->argv[0], "PWD"))
		ft_pwd(bin);
	else if (!ft_strcmp(bin->argv[0], "env") || !ft_strcmp(bin->argv[0], "ENV"))
		ft_env(bin);
	else if (!bin->p_count)
		ft_execve(bin, bin->argv[0], bin->argv);
	ft_close_redifd(bin);
}

void	ft_prepare_parcer(t_bin *bin)
{
	if (!bin->exit_off)
		write (1, "\n", 1);
	bin->to = -1;
	bin->from = -1;
	bin->indx_from = -1;
	bin->indx_to = -1;
	bin->error = 0;
	bin->pid = -1;
	bin->error_ret = 0;
	if (bin->argv && !ft_strcmp(bin->argv[0], "./minishell"))
		launch_minishell();
	ft_bzero(&bin->fds_red, sizeof(bin->fds_red));
	ft_bzero(&bin->fd_pipes, sizeof(bin->fd_pipes));
}

// int make_command_struct()

int	parser(char **argv, char ***envp, t_bin *bin)
{
	// int fd = dup(1);
	// printf("\nfd1 = %d\n", fd);
	// close(fd);
	if (ft_massive_len(bin->argv) > MAX_ARGV)
		return (ft_puts("too much argv. What you try to do?"));
	if (!bin)
		ft_exit(argv);
	bin->envp = *envp;
	bin->argv = argv;
	ft_prepare_parcer(bin);
	if (find_redirects(bin) && !check_pipes(bin))
		ft_redirects(bin, bin->argv);
	bin->argc = ft_massive_len(bin->argv);
	if (!bin->export)
		bin->export = arr_to_dlist(bin->envp);
	if (!bin->envp_lst)
		bin->envp_lst = arr_to_dlist(bin->envp);
	if (bin->to > 0)
		bin->savefd1 = dup(1);
	if (bin->from > 0)
		bin->savefd0 = dup(0);
	if (check_pipes(bin))
		ft_pipes(bin);
	if (!bin->error && !bin->p_count)	
		ft_buildins(bin);
	*envp = bin->envp;
	end_of_parcer(bin);
	// fd = dup(1);
	// printf("\nfd2 = %d\n", fd);
	// close(fd);
	return (0);
}