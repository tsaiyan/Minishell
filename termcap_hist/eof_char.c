#include "header.h"

int eof_char(t_hist *hist)
{
	char	**out;
	int		len_right;
	int		len_left;

	out = NULL;
	len_right = check_len_left_right(hist->right);
	len_left = check_len_left_right(hist->left);
	if (!len_left && !len_right)
	{
		write(1, "exit\n", 5);
		exit(0);
	}
	else if (len_right)
		del_key(hist);
	else
		write (1, "\7", 1);
	return (1);
}
