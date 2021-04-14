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
	char buf[3000];
	ft_bzero(&buf, sizeof(buf));
	char *tmp;
	ft_bzero(&tmp, sizeof(tmp));
	int ret = read(0 ,&buf, 2999);
	while (strcmp(buf,"\n"))
	{
		if (!strcmp(buf, "\4"))
		{
			printf("1");
		}

//		char *o = ft_strdup(buf);
//		tmp = ft_strjoin(tmp, o);
		ret = read(0 ,&buf, 2999);
	}
//	while (!(check_exit(flag)))
//	{
//		write(1, COLOR_BLUE"minishell$ "COLOR_RESET, 20);
//		flag = pre_pars_branching(&p);
//	}
	return (1);
}
//	for (int i = 0; envp[i] != NULL; i++)
//	{
//	printf("%s\n", envp[i]);
//	}

