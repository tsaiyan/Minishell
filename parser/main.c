#include "header.h"

int					check_exit(int flag)
{
	return (flag);
}

int 				main(int argc, char **argv, char *envp[])
{
	int 			flag;
	t_pars			p;
	t_hist			hist;
	struct termios term;

	p.count = 10;
	tcgetattr(0, &term);
	ft_bzero(&p, sizeof(t_pars));
	ft_bzero(&p, sizeof(hist));
	flag = 0;
	p.envp = copy_env_massive(envp);
	history_init(&hist, &term, &p);
	while (!(check_exit(flag)))
	{
		write(1, COLOR_BLUE"minishell$ "COLOR_RESET, 20);
		flag = pre_pars_branching(&p, &hist);
	}
	return (1);
}

//	for (int i = 0; envp[i] != NULL; i++)
//	{
//	printf("%s\n", envp[i]);
//	}

