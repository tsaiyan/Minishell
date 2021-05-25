#include "header.h"

void	check_quotes_subst(char *arg, t_pars *pa, int *i)
{
	if (arg[*i] == S_QUOT && pa->quot_flag == 0)
		pa->quot_flag = 2;
	else if (arg[*i] == S_QUOT && pa->quot_flag == 2)
		pa->quot_flag = 0;
	else if (arg[*i] == W_QUOT && pa->quot_flag == 0)
		pa->quot_flag = 1;
	else if (arg[*i] == W_QUOT && pa->quot_flag == 1)
		pa->quot_flag = 0;
}

static int check_slashes(const char *arg, int *i)
{
	if (arg[*i] == '\\' && arg[*i + 1] != '\0')
	{
		*i += 1;
		return (0);
	}
	return ((arg[*i + 1] == '\0') * 1);
}

int	check_chars_subst(char **arg, t_pars *pa, int *i)
{
	if (arg[0][*i] == ' ')
		check_spaces_prep(*arg + *i, pa);
	else if (arg[0][*i] == '\\')
	{
		if (check_slashes(*arg, i))
		{
			write_error(MULTI_LINE_COMMAND, pa->s);
			return (1);
		}
	}
	else if (arg[0][*i] == S_QUOT || arg[0][*i] == W_QUOT)
		check_quotes_subst(*arg, pa, i);
	else if (arg[0][*i] == '$' && pa->quot_flag == 0)
	{
		pa->tmp_flag = 1;
		if (check_envp(arg, pa, i, STAGE_FIRST))
			return (1);
		*i -= 1;
	}
	else
		pa->tmp_flag = 0;
	return (0);
}
