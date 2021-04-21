#include "header.h"

static int pre_pars(char *arg, t_pars *pa)
{
	int 		i;
//	char 		tmp;
	char 		**ret;

	i = 0;
	pa->s = arg;
	arg = pre_pars_subs(arg, pa);
	if (NULL == arg)
		return (1);
	ret = second_pre_pars(arg, pa);
	if (NULL == ret)
		return (1);
	parser(ret, pa->envp);
	return (0);
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
}

static int check_arguments_if(char **arg, char *buf, t_hist *hist, int len)
{
	int len_arg;

	if (NULL == *arg)
	{
		if (!(*arg = malloc(sizeof(char) * (len + 1))))
			return (1);
		ft_strlcpy(*arg, buf, len + 1);
	}
	else
	{
		len_arg = ft_strlen(*arg);
		if (!(*arg = ft_realloc(*arg, len_arg + len + 1)))
			return (1);
		ft_strlcat(*arg, buf, len_arg + len + 1);
//		ft_bzero(&buf, len_arg);
	}
	return (0);
}

static int check_arguments_realloc(char **arg, char *buf, t_pars *pa,\
	t_hist *hist)
{
	int len;
	int len_arg;

	len = ft_strlen(buf);
	if (0 != check_arguments_if(arg, buf, hist, len))
		return (ft_errors(MALLOC_ERR));
	write(1, buf, len);
	if (NULL != hist->right)
	{
		len_arg = ft_strlen(hist->right);
		if (len_arg)
		{
			write(1, "\e[s", 3);
			write(1, DELETE_CURS_BORD, 4);
			write(1, hist->right, len_arg);
			write(1, "\e[u", 3);
		}
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

int take_argument_for_pre_pars(char **line, t_pars *pa, t_hist *hist)
{
	char 		*arg;
	int 		ret;
	t_pars		s;


	ft_bzero(&s, sizeof(t_pars));
	ret = check_semicolon_and_syntax(*line, &s);
	if (s.quot_flag != 0)
	{
		write_error(MULTI_LINE_COMMAND, *line);
		return (1);
	}
	if (ret < 0)
	{
		write_error(ret, *line);
		return (1);
	}
	while (**line != 0)
	{
		arg = pars_argument_before_semicolon(line, pa);
		if (arg == NULL)
			return (1);
		pre_pars(arg, pa);
	}
	just_freestr_null(line);
	return (0);
}

int pre_pars_branching(t_pars *pa, t_hist *hist)
{
	int				ret;
	char 			buf[2049];
	int 			check;
	char 			*del;

	ft_bzero(&buf, sizeof(buf));
	ret = read(0, buf, 2048);
	while (ft_strcmp(buf, "\n"))
	{
		check = check_esc_char(buf, hist, ret, pa->envp);
		if (!check)
		{
			pa->tmp_flag = check_arguments_realloc(&hist->left, buf, pa, hist);
			if (0 == pa->tmp_flag)
				break ;
			else if (pa->tmp_flag < 0)
				return (1);
		}
		ft_bzero(&buf, sizeof(buf));
		ret = read(0, buf, 4096);
	}
	if (ret == -1)
		ft_errors(SYS_ERR_READ);
	if (add_history_line(hist, buf))
		if (take_argument_for_pre_pars(&hist->left, pa, hist))
			return (0);
	return (0);
}