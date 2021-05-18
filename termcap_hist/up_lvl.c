#include "header.h"

char **alloc_uplvl(char *name_arg, int current_lvl)
{
	char **ret;
	char	*tmp;
	char	*del[2];

	ret = malloc(sizeof(char *) * 3);
	if (!ret)
		return (NULL);
	*ret = ft_strdup(name_arg);
	tmp = ft_strdup("SHLVL=");
	del[0] = tmp;
	del[1] = ft_itoa(current_lvl);
	tmp = ft_strjoin(del[0], del[1]);
	free(del[0]);
	free(del[1]);
	*(ret + 1) = tmp;
	*(ret + 2) = NULL;
	return (ret);
}