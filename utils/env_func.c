#include "header.h"

static int 		check_dollar_quest(char **arg, t_pars *pa, char *str, int *i)
{
	char *env_arg;
	char *tmp;
	char *check;

	env_arg = take_arg_from_env(str, pa);
	if (NULL == env_arg)
		check = "";
	else
		check = env_arg;
	tmp = find_substr_in_str_and_replace(str, *arg, check, i);
	if (NULL == tmp)
		return (1);
	free(*arg);
	free(str);
	if (env_arg)
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
		if (curr_arg[j] == '$' && curr_arg[j + 1] == '$')
			return (ft_strdup("$$"));
		if (j == 1 && ft_isdigit(curr_arg[j]))
			break ;
		else if (ft_isdigit(curr_arg[j]) || ft_isalpha(curr_arg[j]))
			;
		else
			break ;
		j++;
	}
	if (curr_arg[1] == '?')
		j = 2;
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
		if (check_specific_dollar2(arg, pa, i, str))
			return (0);
		str = take_arg(*arg + *i, &num);
		if (NULL == str)
			return (ft_errors(CALLOC_ERR));
		if (check_specific_dollar(arg, pa, i, str))
			return (0);
		else
			check_dollar_quest(arg, pa, str, i);
	}
	return (0);
}

static int	quot_subst_env(char **arg, t_pars *pa, int *i)
{
	char	*str;
	int 	num;

	if (pa->quot_flag == 1)
	{
		num = *i;
		if (check_specific_dollar2(arg, pa, i, str))
			return (0);
		str = take_arg(*arg + *i, &num);
		if (NULL == str)
			return (ft_errors(CALLOC_ERR));
		if (check_specific_dollar(arg, pa, i, str))
			return (0);
		else
			check_dollar_quest(arg, pa, str, i);
	}
	else
		*i += 1;
	return (0);
}

int check_envp(char **curr_arg, t_pars *pa, int *i, int stage)
{

	if (stage == STAGE_FIRST)
	{
		if (0 > no_quot_subst_env(curr_arg, pa, i))
		{
			if (pa->tmp != 1)
				*i -= 1;
			else if (pa->tmp == 2)
				*i += 1;
			return (1);
		}
	}
	if (stage == STAGE_SECOND)
	{
		if (0 > quot_subst_env(curr_arg, pa, i))
			return (1);
		*i -= 1;
	}
	return (0);
}