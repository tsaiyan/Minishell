#include "header.h"
int					check_exit(int flag)
{
	return (flag);
}

int 				main(int argc, char **argv, char *envp[])
{
	int 			flag;
	t_pars			p;

	p.count = 10;
	ft_bzero(&p, sizeof(t_pars));
	flag = 0;
//	for (int i = 0; envp[i] != NULL; i++)
//	{
//		printf("%s\n", envp[i]);
//	}
	p.envp = copy_env_massive(envp);
	while (!(check_exit(flag)))
	{
		write(1, COLOR_BLUE"minishell$ "COLOR_RESET, 20);
		flag = pre_pars_branching(&p);
	}
	return (1);
}