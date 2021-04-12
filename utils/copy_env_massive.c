#include "header.h"

static char **copy(char **ret, char **env)
{
	int 	i;
	int 	len;
	int 	j;

	i = -1;
	while (env[++i] != NULL)
	{
		j = -1;
		len = ft_strlen(env[i]);
		ret[i] = ft_calloc(sizeof(char), len + 1);
		if (NULL == ret[i])
			return (NULL);
		while (env[i][++j] != 0)
			ret[i][j] = env[i][j];
	}
	ret[i] = NULL;
	return (ret);
}

char **copy_env_massive(char **env)
{
	char 	**ret;
	int 	i;
	int 	len;

	i = -1;
	len = 0;
	while (env[++i] != NULL)
	{
		len++;
	}
	ret = ft_calloc(sizeof(char *), len + 1);
	if (NULL == ret)
		return (NULL);
	return (copy(ret, env));
}