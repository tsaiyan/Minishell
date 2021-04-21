#include "header.h"

void 		move_to_cours_toleft(int len)
{
	while (len)
	{
		write(1, "\e[D", 3);
		len--;
	}
}



static void check_currline_number(t_hist *hist, int len_left)
{
	int 		len;

	len = ft_strlen(hist->h[hist->curr_line]);
	hist->left = ft_calloc(len, 1);
	if (!hist->left)
	{
		ft_errors(errno);
		exit(errno);
	}
	ft_strlcpy(hist->left, hist->h[hist->curr_line], len + 1);
	move_to_cours_toleft(len_left);
	write(1, "\x1b[0J", 4);
	write(1, hist->left, ft_strlen(hist->left));
}

static int up_arrow2(t_hist *hist, int len)
{
	if (hist->curr_line - 1 >= 0)
	{
		hist->curr_line--;
		check_currline_number(hist, len);
	}
	return (1);
}

int up_arrow(t_hist *hist)
{
	int 		len;
	char		*del;

	if (hist->curr_line == 0)
		return ((int)write (1, "\7", 1));
	if (hist->left)
		len = ft_strlen(hist->left);
	else
		len = 0;
	if (hist->h_len != hist->curr_line)
	{
		del = hist->h[hist->curr_line];
		hist->h[hist->curr_line] = ft_strjoin(hist->left, hist->right);
		if (del)
			free(del);
	}
	if (hist->h_len == hist->curr_line)
	{
		if (hist->tmp_line)
			free(hist->tmp_line);
		hist->tmp_line = ft_strjoin(hist->left, hist->right);
		free(hist->left);
		hist->left = NULL;
	}
	else
	{
		if (NULL != hist->left)
		{
			free(hist->left);
			hist->left = NULL;
		}
	}
	if (hist->right)
	{
		free(hist->right);
		hist->right = NULL;
	}
	return (up_arrow2(hist, len));
}