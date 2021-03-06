#include "header.h"

static void	change_empty_spaces(char **arg)
{
	int	i;
	int	j;

	i = -1;
	while (arg[++i] != NULL)
	{
		j = -1;
		while (arg[i][++j] != 0)
		{
			if (arg[i][j] == EMPTY_SPACE)
				arg[i][j] = ' ';
		}
	}
}

char	**second_pre_pars(char *arg, t_pars *pa)
{
	char	*tmp;
	char	**ret;
	int		i;

	i = -1;
	tmp = arg;
	pa->quot_flag = 0;
	pa->s = arg;
	while (arg[++i] != 0)
	{
		if ((check_char(&arg, pa, &i)))
			return (NULL);
	}
	tmp = copy_new_prepars_str_without(arg);
	free(arg);
	if (NULL == tmp)
		return (NULL);
	ret = ft_split(tmp, ' ');
	if (NULL == ret)
		return (NULL);
	free(tmp);
	change_empty_spaces(ret);
	return (ret);
}
//				test
// 'e''c''h''o' $www "$www" '$www'

//	ret = ft_split(arg, " ");
//	if (change_massive(ret, pa))
//		return (NULL);
