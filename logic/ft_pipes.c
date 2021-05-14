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
	bin->p_commands = ft_calloc(sizeof(char **), (bin->p_count + 1 + 1));
	if (!bin->p_commands)
		exit(errno);
    // маллок аргументов (сначала комманд ***)
	bin->p_argvs = ft_calloc(sizeof(char *), (bin->p_count + 1 + 1));
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

int	ft_pipes(t_bin *bin)
{
	int i = 0;
	//int pid;
	int fd_in = -1;
	int fd_out = -1;
	int wait_count = bin->p_count;
	// array for fd
	int fd_pipes[bin->p_count + 1][2];
	// write arrays with pipes
	write_pipes(bin);
	// main cycle
	while(bin->p_commands[i])
	{
		// add check
		pipe(fd_pipes[i]);
		// [0] - 0 out
		// [1] - 1 in	
		fd_in = fd_pipes[i][1];
		bin->pid = fork();
		if (i == 0 && bin->pid == 0)
		{
		//	puts("\nchild 1");
			//close(fd_out);
			// close(1);
			// close(0);
			dup2(fd_in, 1);
			close(fd_pipes[i][0]);
			ft_execve(bin, bin->p_commands[i], bin->p_argvs[i]);
			exit(errno);
		}
		if (bin->pid == 0)
		{
		//	puts("child 2");
			// close(0);
			close(fd_in);
			fd_out = fd_pipes[i - 1][0];
			dup2(fd_out, 0);
			ft_execve(bin, bin->p_commands[i], bin->p_argvs[i]);
			exit(errno);
		}
		i++;
	}
	while (wait_count--)
		wait(NULL);
	return(0);
}