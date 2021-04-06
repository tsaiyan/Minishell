#include "header.h"

static int 		check_dollar_quest(char **arg, t_pars *pa, char *str, int *i)
{
	char		*env_arg;
	char 		*tmp;

	env_arg = take_arg_from_env(arg, str, i, pa);
	tmp = find_substr_in_str_and_replace(str, *arg, env_arg, i);
	if (NULL == tmp)
		return (1);
	free(*arg);
	free(str);
	free(env_arg);
	*arg = tmp;
	return (0);
}


static char *take_arg(char *curr_arg, int *i)
{
	int 	j;
	int 	tmp;
	char 	*ret;

	j = 1;
	tmp = -1;
	while (ft_isalnum(curr_arg[j]))
	{
		if (j == 1 && ft_isdigit(curr_arg[j]))
		{
			j++;
			break ;
		}
		else if (ft_isdigit(curr_arg[j]) || ft_isalpha(curr_arg[j]))
			j++;
		else
			break ;
	}
	ret = ft_calloc(sizeof(char), j + 1);
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
		if (arg[0][*i + 1] == '\t' || arg[0][*i + 1] == ' ')
		{
			*i += 1;
			return (0);
		}
		str = take_arg(*arg + *i, &num);
		if (NULL == str)
			return (ft_errors(CALLOC_ERR));
		if (ft_isdigit(str[1]))
			find_substr_in_str_and_replace(str, *arg, "", i);
		else
			check_dollar_quest(arg, pa, str, i);
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

