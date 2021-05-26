#include "header.h"

static int	read_filehistory2(t_hist *hist, char **line, char ***del, char ***h)
{
	*del = *h;
	*h = ft_realloc_2massive(del, *line, hist->h_len++);
	ft_free_massive(*del);
	return (1);
}

static void	free_hist(t_hist *hist, char ***h)
{
	hist->curr_line = hist->h_len;
	hist->tmp_line = NULL;
	hist->h = *h;
}

int	read_filehistory(t_hist *hist, int flag, char *line)
{
	char	**h;
	char	**del;

	h = NULL;
	hist->h_len = 0;
	flag = get_next_line(hist->fd_for_add, &line);
	while (flag != 0)
	{
		del = h;
		h = ft_realloc_2massive(&del, line, hist->h_len++);
		ft_free_massive(del);
		if (!h)
			return (-1);
		free(line);
		flag = get_next_line(hist->fd_for_add, &line);
	}
	if (flag == -1)
		return (-1);
	if (*line != 0)
		read_filehistory2(hist, &line, &del, &h);
	free(line);
	if (!h)
		return (-1);
	free_hist(hist, &h);
	return (1);
}

//del = h;
//h = ft_realloc_2massive(&del, line, hist->h_len++);
//ft_free_massive(del);
