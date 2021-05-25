#include "header.h"

static int	add_history_line2(t_hist *hist)
{
	int		len;
	char	**h;

	len = (int)ft_strlen(hist->left);
	write(hist->fd_for_add, hist->left, len);
	write(hist->fd_for_add, "\n", 1);
	h = ft_realloc_2massive(&hist->h, hist->left, hist->h_len++);
	ft_free_massive(hist->h);
	hist->curr_line = hist->h_len;
	hist->h = h;
	return (1);
}

int	add_history_line(t_hist *hist, char *buf)
{
	char	*del;

	term_off(hist);
	del = hist->left;
	hist->left = ft_strjoin(del, hist->right);
	if (hist->left)
		trim_space_in_begin(&hist->left, 0, 0, 0);
	if (!hist->left && *buf != '\n')
	{
		ft_errors(errno);
		exit(errno);
	}
	just_freestr_null(&del);
	just_freestr_null(&hist->right);
	hist->right = NULL;
	if (check_empty_history(hist, buf))
	{
		def_freestr_null(&hist->left);
		write(1, "\n", 1);
		return (0);
	}
	return (add_history_line2(hist));
}
