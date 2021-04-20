#include "header.h"

static void alloc_exit(char ***out)
{
	*out = malloc(sizeof(char *) * 2);
	if (*out == NULL)
	{
		ft_errors(errno);
		exit(errno);
	}
	**out = ft_strdup("exit");
	if (**out == NULL)
	{
		ft_errors(errno);
		exit(errno);
	}
	**(out + 1) = NULL;
}

int eof_char(t_hist *hist, char **env)
{
	char 		**out;
	int 		len_right;
	int 		len_left;

	out = NULL;
	len_right = check_len_left_right(hist->right);
	len_left = check_len_left_right(hist->left);
	if (!len_left && !len_right)
	{
		alloc_exit(&out);
		parser(out, env);
	}
	else if (len_right)
		del_key(hist);
	else
		write (1, "\7", 1);
	return (1);
}