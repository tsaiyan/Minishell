#include "header.h"

static int read_filehistory2(t_hist *hist, char **line, char *del, char **h)
{

}

int	read_filehistory(t_hist *hist)
{
	char	*line;
	char	**h;
	char	**del;
	int		flag;

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
	{
		read_filehistory2(hist, &line, *del);
		del = h;
		h = ft_realloc_2massive(&del, line, hist->h_len++);
		ft_free_massive(del);
		if (!h)
			return (-1);
	}
	hist->curr_line = hist->h_len;
	hist->tmp_line = NULL;
	free(line);
	hist->h = h;
	return (1);
}
