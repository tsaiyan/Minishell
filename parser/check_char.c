#include "header.h"

int	check_back_slash(char *cur_arg, t_pars *pa, int i)
{
	if (cur_arg[1 + i] == 0)
		return (write_error(MULTI_LINE_COMMAND, pa->s));
	if (pa->quot_flag == 0)
		cur_arg[i] = EMPTY_BACK_SLASH;
	if (cur_arg[i + 1] == ' ')
		cur_arg[i + 1] = EMPTY_SPACE;
	return (0);
}

int	check_quotes(char *cur_arg, t_pars *pa, int i)
{
	if (cur_arg[i] == S_QUOT && pa->quot_flag == 0)
	{
		cur_arg[i] = EMPTY_S_QUOT;
		pa->quot_flag = 2;
	}
	else if (cur_arg[i] == S_QUOT && pa->quot_flag == 2)
	{
		cur_arg[i] = EMPTY_S_QUOT;
		pa->quot_flag = 0;
	}
	else if (cur_arg[i] == W_QUOT && pa->quot_flag == 0)
	{
		cur_arg[i] = EMPTY_W_QUOT;
		pa->quot_flag = 1;
	}
	else if (cur_arg[i] == W_QUOT && pa->quot_flag == 1)
	{
		cur_arg[i] = EMPTY_W_QUOT;
		pa->quot_flag = 0;
	}
	return (0);
}

static int	check_pipes_in_pre(char **cur_arg, t_pars *pa, int *i)
{
	char	*del;

	if (pa->quot_flag == 0)
	{
		del = *cur_arg;
		*cur_arg = find_substr_in_str_and_replace("|", *cur_arg, " | ", i);
		free(del);
		*i += 2;
	}
	return (0);
}

static int	check_redirects(char **cur_arg, t_pars *pa, int *i)
{
	if (pa->quot_flag == 0)
	{
		if (cur_arg[0][*i] == '<')
			cur_arg[0][*i] = RVRS_RDRCT;
		if (cur_arg[0][*i] == '>')
			cur_arg[0][*i] = FRWRD_RDRCT;
	}
	return (0);
}

int	check_char(char **cur_arg, t_pars *pa, int *i)
{
	if (cur_arg[0][*i] == '\\')
	{
		if (0 > check_back_slash(*cur_arg, pa, *i))
			return (1);
		*i += 1;
	}
	else if (cur_arg[0][*i] == S_QUOT || cur_arg[0][*i] == W_QUOT)
		check_quotes(*cur_arg, pa, *i);
	else if (cur_arg[0][*i] == '$')
		check_envp(cur_arg, pa, i, STAGE_SECOND);
	else if (cur_arg[0][*i] == ' ' && pa->quot_flag != 0)
		cur_arg[0][*i] = EMPTY_SPACE;
	else if (cur_arg[0][*i] == '|')
		check_pipes_in_pre(cur_arg, pa, i);
	else if (cur_arg[0][*i] == '<' || cur_arg[0][*i] == '>')
		check_redirects(cur_arg, pa, i);
	return (0);
}
