#include "header.h"

char	*do_absolute_exec_path(char **apple)
{
	char	*r;
	char	*del;
	int		tmp_i;
	int		path_len;

	tmp_i = 0;
	path_len = (int)ft_strlen(*apple) - 10;
	r = find_substr_in_str_and_replace("executable_path=", *apple, "", &tmp_i);
	del = r;
	r = find_substr_in_str_and_replace("minishell", del, "", &path_len);
	free(del);
	return (r);
}
