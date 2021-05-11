#include "header.h"

int 			backspace_key(char *buf, int len, t_hist *hist)
{
	size_t		len_left;
	int 		len_arg;

	len_left = 0;
	if (NULL != hist->left)
		len_left = (int)ft_strlen(hist->left);
	if (len_left)
	{
		write(1, "\e[D", 3);
		write(1, "\e[s", 3);
		write(1, DELETE_CURS_BORD, 4);
		if (hist->right)
		{
			len_arg = (int)ft_strlen(hist->right);
			write(1, hist->right, len_arg);
		}
		write(1, "\e[u", 3);
		hist->left = ft_realloc(hist->left, (int)len_left);
	}
	return (1);
}

int del_key(t_hist *hist)
{
	int 		len_right;
	char 		*tmp;

	len_right = 0;
	if (NULL != hist->right)
		len_right = (int)ft_strlen(hist->right);
	if (len_right && hist->right)
	{
		write(1, "\e[s", 3);
		write(1, DELETE_CURS_BORD, 4);
		tmp = hist->right;
		hist->right = ft_calloc(len_right, 1);
		ft_strlcpy(hist->right, tmp + 1, len_right);
		write(1, hist->right, len_right - 1);
		write(1, "\e[u", 3);
		free(tmp);
	}
	return (1);
}