#include "header.h"

t_sig g_sig;

static void ft_fr(char **del)
{
	if (*del != NULL)
		free(*del);
	*del = NULL;
}

int					check_exit(int flag)
{
	return (flag);
}

int 				main(int argc, char **argv, char *envp[], char **apple)
{
	int 			flag;
	t_pars			p;
	t_hist			hist;
	struct termios	term;

	ft_bzero(&g_sig, sizeof(t_sig));
	ft_bzero(&p, sizeof(t_pars));
	flag = 0;
	p.envp = copy_env_massive(envp);
	hist.right = NULL;
	hist.left = NULL;
	hist.terminal = NULL;
	uplvl_take_hist_from_file(&p, &hist, apple);
	while (!(check_exit(flag)))
	{
		// signal(SIGINT, signal_quit);
		history_init(&hist, &term, &p);
		write(1, COL_BLUE"minishell$ "COL_RESET, 20);
		flag = pre_pars_branching(&p, &hist);
		ft_fr(&hist.right);
		ft_fr(&hist.left);
	}
	return (1);
}
