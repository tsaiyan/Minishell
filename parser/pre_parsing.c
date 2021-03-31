#include "header.h"

static int pre_pars(char *arg, t_pars *pa)
{
	while (*arg)
	{

	}
	return (0);
}

static int check_arguments_realloc(char **arg, char *buf, t_pars *pa)
{
	int len;
	int len_arg;

	len = ft_strlen(buf);
	if (NULL == *arg)
	{
		if (!(*arg = malloc(sizeof(char) * (len + 1))))
			return (ft_errors(MALLOC_ERR));
		ft_strlcpy(*arg, buf, len + 1);
	}
	else
	{
		len_arg = ft_strlen(*arg);
		if (!(*arg = ft_realloc(*arg, len_arg + len + 1)))
			return (ft_errors(CALLOC_ERR));
		ft_strlcat(*arg, buf, len_arg + len + 1);
//		ft_bzero(&buf, len_arg);
	}
	if (ft_strchr(*arg, '\n'))
		return (0);
	return (1);
}

int pre_pars_branching(char *envp[], t_pars *pa)
{
	int				ret;
	char 			buf[11];
	char			*arg;

	arg = NULL;
	while (0 < (ret = read(0, buf, 10)))
	{
		buf[ret] = '\0';
		if (0 == (pa->tmp_flag = check_arguments_realloc(&arg, buf, pa)))
			break ;
		else if (pa->tmp_flag < 0)
			return (1);
	}
	if (ret == -1)
		ft_errors(SYS_ERR_READ);
	pre_pars(arg, pa);
	free(arg);
	return (0);
}