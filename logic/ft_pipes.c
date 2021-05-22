#include "header.h"

// check pipes

int		check_pipes(t_bin *bin)
{
	int i = 0;
	int ret = 0;
	while (bin->argv[i])
	{
		if (!ft_strcmp(bin->argv[i], "|"))
			ret++;
		i++;
	}
	bin->p_count = ret;
	return (ret);
}

int ft_write_red_fd_in_pipes(t_bin *bin, char *command, int i, int c)
{
	int ret;
	int j;

	// j = i;
	// if (flag)
	// 	j--;
	ret = 0;
	if (!ft_strcmp(command, ">"))
	{
		ret = open(bin->argv[i + 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
		if (check_ret(bin, ret, bin->argv[i + 1]) == -1)
			return (-1);
		bin->fds_red[c][1] = ret;
		return (1);
	}
	if (!ft_strcmp(command, ">>"))
	{
		ret = open(bin->argv[i + 1], O_CREAT | O_RDWR | O_APPEND, 0666);
		if (check_ret(bin, ret, bin->argv[i + 1]) == -1)
			return (-1);
		bin->fds_red[c][1] = ret;
		return (1);
	}
	if (!ft_strcmp(command, "<"))
	{
		ret = open(bin->argv[i + 1], O_RDONLY);
		if (check_ret(bin, ret, bin->argv[i + 1]) == -1)
			return (-1);
		bin->fds_red[c][0] = ret;
		return (1);
	}
	return (0);
}

int		write_pipes(t_bin *bin)
{

	int i = 0;
	int c = 0;
	int k = 0;
    int n = 0;
	int ret;
    // маллок комманд
	bin->p_commands = (char **)ft_calloc(sizeof(char *), (bin->p_count + 1 + 1));
	if (!bin->p_commands)
		exit(errno);
    // маллок аргументов (сначала комманд ***)
	bin->p_argvs = (char ***)ft_calloc(sizeof(char **), (bin->p_count + 1 + 1));
	if (!bin->p_argvs)
		exit(errno);
	while (bin->argv[i])
	{
        // пропуск пайпов
		if (!ft_strcmp(bin->argv[i], "|"))
		{
			//bin->argv = ft_del_index_in2massive(bin->argv, i);
			i++;
			continue;
		}
		        // запись комманды
		if (!its_redirect(bin->argv[i]))
			bin->p_commands[c] = bin->argv[i];
		if (ft_write_red_fd_in_pipes(bin, bin->argv[i], i, c))
		{
			bin->argv = ft_del_index_in2massive(bin->argv, i);
			if (bin->argv[i] || ft_strcmp(bin->argv[i], "|"))
				bin->argv = ft_del_index_in2massive(bin->argv, i);
		}
		if (ft_write_red_fd_in_pipes(bin, bin->argv[i + 1], i + 1, c))
		{
			bin->argv = ft_del_index_in2massive(bin->argv, i + 1);
			if (bin->argv[i + 1] || ft_strcmp(bin->argv[i], "|"))
				bin->argv = ft_del_index_in2massive(bin->argv, i + 1);
		}
		if (bin->error_ret)
			return (-1);


        // запись аргументов
        // считаем к-во для маллока
        n = i;
        while (bin->argv[n] && ft_strcmp(bin->argv[n], "|"))
            n++;
        // маллок аргументов (**) (1 for null and 1 for command)
		bin->p_argvs[c] = ft_calloc(sizeof(char *), n + 1 + 1);
        if (!bin->p_argvs[c])
		    exit(errno);
        // в argv сначала команда
        bin->p_argvs[c][k] = bin->argv[i];
        k++;
        i++;
        // затем остальное
		while (bin->argv[i] && ft_strcmp(bin->argv[i], "|"))
		{
			bin->p_argvs[c][k] = bin->argv[i];
			k++;
			i++;
		}
		k = 0;
		c++;
	}
    return (0);
}

void	free_pipes(t_bin *bin)
{
	int i = 0;
	free(bin->p_commands);
	while (bin->p_argvs[i])
	{
		free(bin->p_argvs[i]);
		i++;
	}
	free(bin->p_argvs);
}

int		redirect_index(int index, int i, t_bin *bin)
{
	if (i == 0 && (bin->to > 0 || bin->from > 0))
		return (0);
	else if (i == 0)
		return (-1);
	return (index - ft_massive_len(bin->p_argvs[i]) - bin->del_pipes + 1);
}

int		it_not_builtin(char *command)
{
	if (!ft_strcmp(command, "pwd") || !ft_strcmp(command, "echo") || \
	!ft_strcmp(command, "env") || \
	!ft_strcmp(command, "exit") || !ft_strcmp(command, "unset") || \
	!ft_strcmp(command, "export") || !ft_strcmp(command, "cd"))
		return (0);
	return (1);
}

int		builtin_pipes(t_bin *bin, char *command, char **argv)
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
	int status;

	if (bin->pid == 0)
	{
		bin->exit_status = execve(execve_str, argv, bin->envp);
		// if (argv[0][0] == '.' && argv[0][1] == '/')
		// 	exit(command_error(argv[0], 5));
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
			ft_pipe_execve(bin, execve_str,  bin->p_argvs[i]);
	}
	return (0);
}

// int	close_pipes_fd(t_bin *bin, int i)
// {

// }

int		ft_pipes(t_bin *bin)
{
	int i;
	char *execve_str;

	bin->pid = -1;
	i = 0;
	execve_str = NULL;
	if (write_pipes(bin) == -1)
		return (-1);
	while(bin->p_commands[i])
	{
		if (it_not_builtin(bin->p_commands[i]))
			execve_str = get_excve_str(bin, bin->p_commands[i], bin->p_argvs[i]);
		daughter_run(bin, execve_str, i);
		close(bin->fd_pipes[i][1]);
		if (i > 0)
			close(bin->fd_pipes[i - 1][0]);
		if (execve_str)
			free(execve_str);
		i++;
	}
	close(bin->fd_pipes[i - 1][0]);
	while(wait(NULL) > 0);
	free_pipes(bin);
	return (0);
}