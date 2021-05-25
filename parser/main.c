#include "header.h"

static void	ft_fr(char **del)
{
	if (*del != NULL)
		free(*del);
	*del = NULL;
}

int	check_exit(int flag)
{
	return (flag);
}

int	main(int argc, char **argv, char *envp[], char **apple)
{
	int				flag;
	t_pars			p;
	t_hist			hist;
	struct termios	term;

	(void)argv;
	(void)argc;
	ft_bzero(&g_sig, sizeof(t_sig));
	ft_bzero(&p, sizeof(t_pars));
	ft_bzero(&hist, sizeof(t_hist));
	flag = 0;
	p.envp = copy_env_massive(envp);
	uplvl_take_hist_from_file(&p, &hist, apple);
	while (!(check_exit(flag)))
	{
		signal(SIGINT, signal_exit);
		signal(SIGQUIT, signal_quit);
		p.b->exit_off = 0;
		history_init(&hist, &term);
		write(2, COL_BLUE"minishell$ "COL_RESET, 20);
		flag = pre_pars_branching(&p, &hist, 0, 0);
		ft_fr(&hist.right);
		ft_fr(&hist.left);
	}
	return (1);
}
