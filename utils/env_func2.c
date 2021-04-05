#include "header.h"

static char *alloc_env_arg(const char *env)
{
	int 	i;
	int		j;
	int 	tmp;
	char	*ret;

	i = -1;
	j = 0;
	while (env[++i] != '=')
		;
	tmp = i;
	while (env[++i] != '\0')
		j++;
	ret = ft_calloc(sizeof(char), j);
	// + 1
	if (NULL == ret)
		return (NULL);
	j = -1;
	while (++tmp != i)
		ret[++j] = env[tmp];
	return (ret);
}

static char	*take_arg(char **env, char *str)
{
	int 	i;
	int 	j;
	int 	flag;

	j = -1;
	while (env[++j] != NULL)
	{
		i = -1;
		flag = 0;
		while (env[j][++i] != '=')
		{
			if (str[i + 1] != 0)
			{
				if (env[j][i] != str[i + 1])
				{
					flag = 1;
					break ;
				}
			}
		}
		if (flag != 1)
			return (alloc_env_arg(env[j]));
	}
	return (NULL);
}

char		*take_arg_from_env(char **arg, char *str, int *i, t_pars *pa)
{
	char 	*exp_arg;

	exp_arg = take_arg(pa->envp, str);
	return (exp_arg);
}