#include "header.h"

static void double_forward_redirect(char **cur_arg, int *i)
{
	char	*del;

	del = *cur_arg;
	*cur_arg = find_substr_in_str_and_replace(">", *cur_arg, " > ", i);
	free(del);
	*i += 2;
}

void	check_forward_redirect(char **cur_arg, t_pars *pa, int *i)
{
	char	*del;

	if (pa->quot_flag == 0)
	{
		if (cur_arg[0][*i] == '<')
		{
			del = *cur_arg;
			*cur_arg = find_substr_in_str_and_replace("|", *cur_arg, " | ", i);
			free(del);
			*i += 2;
		}
		else if (cur_arg[0][*i] == '>')
		{
			if (cur_arg[0][*i + 1] == '>')
			{
				double_forward_redirect(cur_arg, i);
				return ;
			}
			del = *cur_arg;
			*cur_arg = find_substr_in_str_and_replace(">>", *cur_arg, " >> ", i);
			free(del);
			*i += 3;
		}
	}
}