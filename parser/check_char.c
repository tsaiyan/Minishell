#include "header.h"

int	check_back_slash(char *cur_arg, t_pars *pa, int i)
{
	if (cur_arg[1 + i] == 0)
		return (write_error(MULTI_LINE_COMMAND, pa->s));
	
	cur_arg[i] = EMPTY_BACK_SLASH;
	if (cur_arg[i + 1] == ' ')
		cur_arg[i + 1] = EMPTY_SPACE;
	return (0);
}

//	if (pa->back_slash == 0)
//	{
//		cur_arg[i] = EMPTY_BACK_SLASH;
//		pa->back_slash = 1;
//	}

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
	return (0);
}
