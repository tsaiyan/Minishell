#include "header.h"

void	launch_minishell(char ***envp, t_bin *b)
{
	// pid_t	pid;
	// int		exit_status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	// pid = fork();
	// if (!pid)
	// {
	// 	if (execve("./minishell", NULL, *envp))
	// 		exit(1);
	// }
	// else
	// {
	// 	waitpid(pid, )
	// }
}