#include "header.h"

char *second_pre_pars(char *arg, t_pars *pa)
{
	char		*tmp;
	int			i;

	i = -1;
	tmp = arg;
	arg = ft_strtrim(tmp, " ");
	free(tmp);
	while (arg[++i] != 0)
	{
		if ((check_char(arg, pa, &i)))
			return (NULL);
	}
	tmp = copy_new_prepars_str(arg);
	if (NULL == tmp)
		return (NULL);
	free(arg);
	return (tmp);
}