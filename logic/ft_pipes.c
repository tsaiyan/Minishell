#include "header.h"

// check pipes

int	check_pipes(t_bin *bin)
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
	return(ret);
}

int	write_pipes(t_bin *bin)
{
    // маллок комманд
	bin->p_commands = (char **)ft_calloc(sizeof(char *), (bin->p_count + 1 + 1));
	if (!bin->p_commands)
		exit(errno);
    // маллок аргументов (сначала комманд ***)
	bin->p_argvs = (char ***)ft_calloc(sizeof(char **), (bin->p_count + 1 + 1));
	if (!bin->p_argvs)
		exit(errno);
	int i = 0;
	int c = 0;
	int k = 0;
    int n = 0;
	while (bin->argv[i])
	{
        // пропуск пайпов
		if (!ft_strcmp(bin->argv[i], "|"))
		{
			i++;
			continue;
		}
        // запись комманды
		bin->p_commands[c] = bin->argv[i];

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

int		ft_pipes(t_bin *bin)
{
	int i = -1;
	bin->pid= -1;
	char *execve_str = NULL;
	int fd_pipes[bin->p_count + 1][2];
	//write(1, "\n", 1);
	write_pipes(bin);

	i = 0;
	while(bin->p_commands[i])
	{
		execve_str = get_excve_str(bin, bin->p_commands[i], bin->p_argvs[i]);
		pipe(fd_pipes[i]);
		bin->pid = fork();
		if (bin->pid == 0)
		{
			if (i == 0 || i < bin->p_count)
				dup2(fd_pipes[i][1], 1);
			else if (i == (bin->indx_from - ft_massive_len(bin->p_argvs[i])))
				dup2(bin->from, 0);
			else if (i != 0)
				dup2(fd_pipes[i - 1][0], 0);
			if (i == (bin->indx_to - ft_massive_len(bin->p_argvs[i])))
				dup2(bin->indx_to, 1);
			ft_execve(bin, execve_str, bin->p_argvs[i]);
		}
		close(fd_pipes[i][1]);
		if (i > 0)
			close(fd_pipes[i - 1][0]);
		free(execve_str);
		i++;
	}
	close(fd_pipes[i - 1][0]);
	while(wait(NULL) > 0);
	free_pipes(bin);
	return(0);
}