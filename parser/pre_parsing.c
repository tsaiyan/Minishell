#include "header.h"

static char *pre_pars_subs(char *arg, t_pars *pa)
{
	char 		*ret;
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

static int pre_pars(char *arg, t_pars *pa)
{
	int 		i;
	char 		tmp;

	i = 0;
	pa->s = arg;
	arg = pre_pars_subs(arg, pa);

	if (NULL == arg)
		return (1);
	printf("%s\n", arg);
	pa->s = arg;
//	while (arg[i] != 0)
//	{
//		if (arg[i] == ';')
//			return (0);
//		if (check_char(arg + i, pa))
//			return (1);
//		i++;
//	}
//	i = -1;
//	while (arg[++i] != 0)
//	{
//		if (arg[i] >= 0)
//			ft_putchar_fd(arg[i], 1);
//	}
//	ft_putchar_fd('\n', 1);
	free(arg);
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
	{
		len_arg = ft_strlen(*arg);
		arg[0][len_arg - 1] = 0;
		//hzzhzhzhz
		return (0);
	}
	return (1);
}

int check_semicolon(char *line, t_pars *pa)
{

}

int pre_pars_branching(char *envp[], t_pars *pa)
{
	int				ret;
	char 			buf[11];
	char			*arg;

	arg = NULL;
	ret = read(0, buf, 10);
	while (0 < ret)
	{
		buf[ret] = '\0';
		pa->tmp_flag = check_arguments_realloc(&arg, buf, pa);
		if (0 == pa->tmp_flag)
			break ;
		else if (pa->tmp_flag < 0)
			return (1);
		ret = read(0, buf, 10);
	}
	if (ret == -1)
		ft_errors(SYS_ERR_READ);
	pre_pars(arg, pa);
//	free(arg);
	return (0);
}