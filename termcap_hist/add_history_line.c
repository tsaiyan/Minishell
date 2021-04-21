#include "header.h"

static int 				add_history_line2(t_hist *hist)
{
	int 			len;
	char 			**h;

	len = (int)ft_strlen(hist->left);
	write(hist->fd_for_add, hist->left, len);
	write(hist->fd_for_add, "\n", 1);
	h = ft_realloc_2massive(&hist->h, hist->left, hist->h_len++);
	ft_free_massive(hist->h);
	hist->curr_line = hist->h_len;
	hist->h = h;
//	if (hist->tmp_line)
//	{
//		free(hist->tmp_line);
//		hist->tmp_line = NULL;
//	}
	return (1);
}

int 				add_history_line(t_hist *hist)
{
	char 			*del;

	term_off(hist);
	del = hist->left;
	hist->left = ft_strjoin(del, hist->right);
	free(del);
	free(hist->right);
	hist->right = NULL;
	return (add_history_line2(hist));
}