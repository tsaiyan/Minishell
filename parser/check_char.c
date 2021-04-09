#include "header.h"

int 			check_back_slash(char *cur_arg, t_pars *pa)
{
	if (cur_arg[1] == 0)
		return (write_error(MULTI_LINE_COMMAND, pa->s));
	if (pa->back_slash == 0)
	{
		*cur_arg = EMPTY_BACK_SLASH;
		pa->back_slash = 1;
	}
	return (0);
}

int 			check_quotes(char *cur_arg, t_pars *pa)
{
	if (*cur_arg == S_QUOT && pa->quot_flag == 0)
	{
		*cur_arg = EMPTY_S_QUOT;
		pa->quot_flag = 2;
	}
	else if (*cur_arg == S_QUOT && pa->quot_flag == 2)
	{
		*cur_arg = EMPTY_S_QUOT;
		pa->quot_flag = 0;
	}
	else if (*cur_arg == W_QUOT && pa->quot_flag == 0)
	{
		*cur_arg = EMPTY_W_QUOT;
		pa->quot_flag = 1;
	}
	else if (*cur_arg == W_QUOT && pa->quot_flag == 1)
	{
		*cur_arg = EMPTY_W_QUOT;
		pa->quot_flag = 0;
	}
	return (0);
}

int check_char(char *cur_arg, t_pars *pa, int *i)
{
	if (*cur_arg == '\\')
	{
		if (0 > check_back_slash(cur_arg, pa))
			return (1);
	}
	else if (*cur_arg == S_QUOT || *cur_arg == W_QUOT)
		check_quotes(cur_arg, pa);
	else if (*cur_arg == '$')
		check_envp(&cur_arg, pa, i, STAGE_SECOND);

//	else if (*cur_arg == S_QUOT && pa->quot_flag == 0)
//	{
//		pa->quot_flag = 2;
//
//	}
	return (0);
}

