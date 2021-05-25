#include "header.h"

static void	do_history_dir(char *str1, char *str2, char ***envp, t_bin *bin)
{
	char	**com;
	int		tmp_exit_status;

	com = malloc(sizeof(char *) * 3);
	if (com == NULL)
	{
		ft_errors(MALLOC_ERR);
		exit(MALLOC_ERR);
	}
	com[0] = ft_strdup(str1);
	com[1] = ft_strdup(str2);
	com[2] = NULL;
	tmp_exit_status = g_sig.exit_status;
	bin->exit_off = 1;
	parser(com, envp, bin);
	bin->exit_off = 0;
	g_sig.exit_status = tmp_exit_status;
}

static char	*take_history_filename(t_pars *pa, t_hist *hist, char *del)
{
	char	*str_lvl;
	char	*ret;
	DIR		*dir;

	str_lvl = ft_itoa(hist->SHLVL);
	del = str_lvl;
	str_lvl = ft_strjoin("/hist_", del);
	free(del);
	dir = opendir(".history");
	if (dir == NULL)
	{
		if (errno == ENOENT)
			do_history_dir("mkdir", ".history", &pa->envp, pa->b);
		else
		{
			ft_errors(errno);
			write(2, "Error occurred while creating the file history\n", 47);
			exit(errno);
		}
	}
	if (dir)
		closedir(dir);
	ret = ft_strjoin(".history", str_lvl);
	free(str_lvl);
	return (ret);
}

static int	up_lvl(t_pars *pa, t_hist *hist)
{
	char	*lvl;
	int		tmp_exit_status;

	lvl = take_arg_from_env("$SHLVL", pa);
	if (!lvl)
		hist->SHLVL = 1;
	else
	{
		hist->SHLVL = ft_atoi(lvl);
		if (hist->SHLVL < 0)
			hist->SHLVL = 0;
		else
			hist->SHLVL++;
	}
	tmp_exit_status = g_sig.exit_status;
	pa->b->exit_off = 1;
	parser(alloc_uplvl("export", hist->SHLVL), &pa->envp, pa->b);
	g_sig.exit_status = tmp_exit_status;
	pa->b->exit_off = 0;
	free(lvl);
	return (0);
}

static int	open_and_take_hist(t_pars *pa, t_hist *hist)
{
	char	*file;
	int		tmp;

	tmp = 0;
	file = take_history_filename(pa, hist, NULL);
	hist->fd_for_add = open(file, O_CREAT | O_RDWR, 0644);
	free(file);
	if (0 > hist->fd_for_add)
	{
		tmp = ft_errors(errno);
		exit(tmp);
	}
	return (0);
}

int	uplvl_take_hist_from_file(t_pars *pa, t_hist *hist, char **apple)
{
	hist->exec_path = do_absolute_exec_path(apple);
	pa->b = malloc(sizeof(t_bin));
	if (!pa->b)
		ft_errors(MALLOC_ERR);
	ft_bzero(pa->b, sizeof(t_bin));
	pa->b->exit_off = 0;
	up_lvl(pa, hist);
	open_and_take_hist(pa, hist);
	if (!pa->b)
	{
		ft_errors(errno);
		exit(errno);
	}
	if (-1 == read_filehistory(hist, 0, NULL))
	{
	}
	return (0);
}
