#include "header.h"

char **alloc_uplvl(char *name_arg, int current_lvl)
{
	char **ret;

	ret = malloc(sizeof(char *) * 3);
	if (!ret)
		return (NULL);
	*ret = ft_strdup(name_arg);
	*(ret + 1) = ft_strdup(ft_itoa(current_lvl));
	*(ret + 2) = NULL;
	return (ret);
}