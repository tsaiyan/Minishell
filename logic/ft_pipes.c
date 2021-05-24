#include "header.h"

int	builtin_pipes(t_bin *bin, char *command, char **argv)
{
	if (!ft_strcmp(command, "pwd"))
		ft_pwd(bin);
	if (!ft_strcmp(command, "echo"))
		ft_echo(bin, argv);
	if (!ft_strcmp(command, "env"))
		ft_env(bin);
	if (!ft_strcmp(command, "exit"))
		ft_exit(argv);
	if (!ft_strcmp(command, "unset"))
		ft_unset(bin, argv);
	if (!ft_strcmp(command, "export"))
		ft_export(bin, argv);
	if (!ft_strcmp(command, "cd"))
		ft_cd(bin, argv);
	exit(0);
}

void	ft_pipe_execve(t_bin *bin, char *execve_str, char **argv)
{
	if (bin->pid == 0)
	{
		bin->exit_status = execve(execve_str, argv, bin->envp);
		if (argv[0][0] == '.' && argv[0][1] == '/')
			exit(command_error(argv[0], 5));
		exit(0);
	}
}

int	daughter_run(t_bin *bin, char *execve_str, int i)
{
	pipe(bin->fd_pipes[i]);
	bin->pid = fork();
	if (bin->pid == 0)
	{
		if (bin->fds_red[i][1])
			dup2(bin->fds_red[i][1], 1);
		else if (i == 0)
			dup2(bin->fd_pipes[i][1], 1);
		else if (i == redirect_index(bin->indx_to, i, bin))
			dup2(bin->to, 1);
		else if (i < bin->p_count)
			dup2(bin->fd_pipes[i][1], 1);
		if (bin->fds_red[i][0])
			dup2(bin->fds_red[i][0], 0);
		else if (i == redirect_index(bin->indx_from, i, bin))
			dup2(bin->from, 0);
		else if (i != 0)
			dup2(bin->fd_pipes[i - 1][0], 0);
		if (!it_not_builtin(bin->p_commands[i]))
			builtin_pipes(bin, bin->p_commands[i], bin->p_argvs[i]);
		else
			ft_pipe_execve(bin, execve_str, bin->p_argvs[i]);
	}
	return (0);
}

void	ft_pipes_close_fd(t_bin *bin, int i, char *execve_str)
{
	close(bin->fd_pipes[i][1]);
	if (i > 0)
		close(bin->fd_pipes[i - 1][0]);
	if (bin->fds_red[i][0])
		close(bin->fds_red[i][0]);
	if (bin->fds_red[i][1])
		close(bin->fds_red[i][1]);
	if (execve_str)
		free(execve_str);
}

void	ft_pipes(t_bin *bin)
{
	int		i;
	char	*execve_str;

	bin->pid = -1;
	i = -1;
	write_pipes(bin);
	while (bin->p_commands[++i])
	{
		 execve_str = NULL;
		if (it_not_builtin(bin->p_commands[i]))
			execve_str = \
			get_excve_str(bin, bin->p_commands[i], bin->p_argvs[i]);
		daughter_run(bin, execve_str, i);
		ft_pipes_close_fd(bin, i, execve_str);
	}
	close(bin->fd_pipes[i - 1][0]);
	while (wait(NULL) > 0)
		continue ;
	free_pipes(bin);
}
