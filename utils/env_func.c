#include "header.h"

//static int 		check_dollar_quest(char *curr_arg, t_pars *pa)
//{
//
//}


static char *take_arg(char *curr_arg, int *i)
{
	int 	j;
	int 	tmp;
	char 	*ret;

	j = 0;
	tmp = -1;
	while (ft_isalnum(curr_arg[j]))
	{
		if (j == 0 && ft_isalnum(curr_arg[j]))
			j++;
		else if (ft_isalpha(curr_arg[j]))
			j++;
		else
			break ;
	}
	ret = ft_calloc(sizeof(char), j);
	// + 1
	if (ret == NULL)
		return (NULL);
	while (++tmp != j)
		ret[tmp] = curr_arg[tmp];
	return (ret);
}

static int	no_quot_subst_env(char **arg, t_pars *pa, int *i)
{
	char	*str;
	int 	num;

	if (pa->quot_flag == 0)
	{
		num = *i;
		str = take_arg(*arg + 1, &num);
		if (NULL == str)
			return (ft_errors(CALLOC_ERR));
	}
	return (0);
}

int check_envp(char **curr_arg, t_pars *pa, int *i, int stage)
{
	if (stage == STAGE_FIRST)
	{
		if (0 > no_quot_subst_env(curr_arg, pa, i))
			return (1);
	}
	if (stage == STAGE_SECOND)
	{

	}
	return (0);
//	char		*arg;
//
//	if (pa->quot_flag == 2)
//		return (0);
//	if (!pa->envp)
//		return (write_error(CANT_ACCESS_ENVP, pa->s));
//	if (*curr_arg[1] == '?' || ft_isdigit(*curr_arg[1]))
//		return (check_dollar_quest(*curr_arg, pa));
//	arg = take_arg(*curr_arg);
}

