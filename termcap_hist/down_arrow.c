#include "header.h"

static void 	write_history_line(t_hist *hist, int len)
{
	move_to_cours_toleft(len);
	write(1, DELETE_CURS_BORD, 4);
	if (hist->left)
		write(1, hist->left, ft_strlen(hist->left));
}

void 			ft_free_left_right(char **left, char **right)
{
	if (left)
	{
		free(*left);
		*left = NULL;
	}
	if (right)
	{
		free(*right);
		*right = NULL;
	}
}

static int work_with_tmpline(t_hist *hist, int old_curr, int len_write)
{
	char 		*tmp;
	char 		*del_l;

	if (old_curr != hist->curr_line)
	{
		del_l = hist->left;
		tmp = hist->h[old_curr];
		hist->h[old_curr] = ft_strjoin(del_l, hist->right);
		if (NULL != tmp)
			free(tmp);
		if (hist->tmp_line)
		{
			hist->left = ft_strdup(hist->tmp_line);
			free(hist->tmp_line);
			hist->tmp_line = NULL;
		}
		else
			hist->left = NULL;
		ft_free_left_right(&del_l, &hist->right);
		write_history_line(hist, len_write);
	}
	else
		write (1, "\7", 1);
	return (1);
}

static int down_arrow2(t_hist *hist, int old_curr, int len_write)
{
	char 		*tmp;
	char 		*del_l;

	del_l = hist->left;
	tmp = hist->h[old_curr];
	hist->h[old_curr] = ft_strjoin(del_l, hist->right);
	if (NULL != tmp)
			free(tmp);
	hist->left = ft_strdup(hist->h[hist->curr_line]);
	ft_free_left_right(&del_l, &hist->right);
	write_history_line(hist, len_write);
	return (1);
}

int down_arrow(t_hist *hist)
{
	int 		old_curr;
	int 		len;

	old_curr = hist->curr_line;
	len = 0;
	if (hist->left)
		len = (int)ft_strlen(hist->left);
	if (hist->h_len > hist->curr_line)
		hist->curr_line++;
	if (hist->h_len == hist->curr_line)
		return (work_with_tmpline(hist, old_curr, len));
	else
		return (down_arrow2(hist, old_curr, len));
}