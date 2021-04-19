#include "header.h"

int 			backspace_key(char *buf, int len, t_hist *hist)
{
	int 		len_left;

	len_left = ft_strlen(buf);
	if (len_left)
	{
		write(1, buf, len);
		hist->left = ft_realloc(hist->left, len_left - 1);
	}
	return (1);
}