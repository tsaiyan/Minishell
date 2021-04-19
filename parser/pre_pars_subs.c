#include "header.h"

char *pre_pars_subs(char *arg, t_pars *pa)
{
	char 		*ret;
	char 		*del;
	int			i;

	i = -1;
	while (arg[++i] != 0)
	{
		if ((check_chars_subst(&arg, pa, &i)))
			return (NULL);
	}
	ret = copy_new_prepars_str(arg);
	if (NULL == ret)
		return (NULL);
	free(arg);
	return (ret);
}