#include "header.h"

int 		check_len_left_right(char *line)
{
	if (line)
		return ((int)ft_strlen(line));
	return (0);
}

int left_arrow(char *buf, int len, t_hist *hist)
{
	int 		len_left;
	int 		len_right;
	char 		*del;

	len_left = check_len_left_right(hist->left);
	len_right = check_len_left_right(hist->right);
	if (len_left)
	{
		write(1, buf, len);
		del = hist->right;
		hist->right = ft_calloc(len_right + 2, 1);
		if (!hist->right)
		{
			len_left = ft_errors(errno);
			exit(len_left);
		}
		hist->right[0] = hist->left[len_left - 1];
		if (len_right)
			ft_strlcat(hist->right + 1, del, len_right + 1);
		free(del);
		hist->left = ft_realloc(hist->left, len_left);
		if (!hist->right || !hist->left)
		{
			len_left = ft_errors(errno);
			exit(len_left);
		}
	}
	return (1);
}

int right_arrow(char *buf, int len, t_hist *hist)
{
	int 		len_left;
	int 		len_right;
	char		tmp[2];
	char 		*del;
	int 		i;

	len_right = check_len_left_right(hist->right);
	len_left = check_len_left_right(hist->left);
	if (len_right)
	{
		write(1, buf, len);
		tmp[0] = hist->right[0];
		tmp[1] = '\0';
		del = hist->left;
		hist->left = ft_strjoin(del, tmp);
		free(del);
		del = hist->right;
		i = 0;
		hist->right = find_substr_in_str_and_replace(tmp, del, "", &i);
		free(del);
	}
	return (1);
}