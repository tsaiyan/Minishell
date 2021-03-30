#include "header.h"

int					check_exit(int flag)
{
	return (flag);
}

int 				main(int argc, char **argv, char *envp[])
{
	int 			flag;
	t_pars			p;

	ft_bzero(&p, sizeof(t_pars));
	p.count = 10;
	flag = 0;
	while (!(check_exit(flag)))
	{
		write(1, COLOR_BLUE"minishell$ "COLOR_RESET, 20);
		flag = pre_pars_branching(envp, &p);
	}
	return (1);
}