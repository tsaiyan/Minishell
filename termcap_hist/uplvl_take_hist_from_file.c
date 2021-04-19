#include "header.h"

static void 	do_history_dir(char *str1, char *str2)
{
	char 		**com;

	com = malloc(sizeof(char*) * 3);
	if (com == NULL)
	{
		ft_errors(MALLOC_ERR);
		exit(MALLOC_ERR);
	}
	com[0] = str1;
	com[1] = str2;
	com[2] = NULL;
}

static char 	*take_history_filename(t_pars *pa, t_hist *hist)
{
	char 		*str_lvl;
	char 		*del;
	char 		*tmp;
	char 		*ret;
	DIR 		*dir;

	str_lvl = ft_itoa(hist->SHLVL);
	del = str_lvl;
	str_lvl = ft_strjoin("/hist_", del);
	free(del);
//	tmp = ft_strjoin(hist->exec_path, "/.history");
//	dir = opendir(tmp);
//	if (dir == NULL)
//	{
//		if (errno == ENOENT)
//			do_history_dir("mkdir", tmp);
//		else
//		{
//			ft_errors(errno);
//			exit(errno);
//		}
//		//add .history to path and execve on mkdir .history
//	}
	ret = ft_strjoin(hist->exec_path, str_lvl);
	free(str_lvl);
	return (ret);
}

static int 		up_lvl(t_pars *pa, t_hist *hist)
{
	char 		*lvl;
	int 		tmp_i;

	tmp_i = 0;
	lvl = take_arg_from_env("SHLVL", pa);
	if (!lvl)
		hist->SHLVL = 1;
	else
	{
		hist->SHLVL = ft_atoi(lvl);
		if (hist->SHLVL < 0)
			hist->SHLVL = 0;
		else
			hist->SHLVL++;
//		(here need export func.) itoa and etc.
	}
	return (0);
}

static int 		open_and_take_hist(t_pars *pa, t_hist *hist)
{
	char 		*file;
	int 		tmp;

	file = take_history_filename(pa, hist);
	hist->fd_for_add = open("hist_1", O_CREAT | O_RDWR, 0644);
	free(file);
	// file too open char *file
	if (0 > hist->fd_for_add)
	{
		tmp = ft_errors(errno);
		exit(tmp);
	}
	return (0);
}

int uplvl_take_hist_from_file(t_pars *pa, t_hist *hist, char **apple)
{
	hist->exec_path = do_absolute_exec_path(apple);
	up_lvl(pa, hist);
	open_and_take_hist(pa, hist);
	if (-1 == read_filehistory(hist))
	{
	}
	return (0);
}