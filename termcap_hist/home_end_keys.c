#include "header.h"

int	home_key(t_hist *hist)
{
	int	len_left;
	int	tmp;

	len_left = check_len_left_right(hist->left);
	if (len_left)
	{
		tmp = len_left;
		while (tmp != 0)
		{
			left_arrow("\e[D", 3, hist);
			tmp--;
		}
	}
	return (1);
}

int	end_key(t_hist *hist)
{
	int	len_right;
	int	tmp;

	len_right = check_len_left_right(hist->right);
	if (len_right)
	{
		tmp = len_right;
		while (tmp != 0)
		{
			right_arrow("\e[C", 3, hist);
			tmp--;
		}
	}
	return (1);
}
