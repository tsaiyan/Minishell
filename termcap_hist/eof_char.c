#include "header.h"

static void alloc_exit(char ***out)
{
	*out = malloc(sizeof(char *) * 3);
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
	**(out + 1) = ft_strdup("1");
	**(out + 2) = NULL;
}

int eof_char(t_hist *hist, char **env, t_bin *b)
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
		write(1, "exit\n", 5);
		parser(out, env, b);
	}
	else if (len_right)
		del_key(hist);
	else
		write (1, "\7", 1);
	return (1);
}