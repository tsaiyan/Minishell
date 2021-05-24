#include "header.h"

static int	pre_pars(char *arg, t_pars *pa)
{
	char	**ret;

	pa->s = arg;
	arg = pre_pars_subs(arg, pa);
	if (NULL == arg)
		return (1);
	ret = second_pre_pars(arg, pa);
	if (NULL == ret)
		return (1);
	parser(ret, &pa->envp, pa->b);
	return (0);
}

static int	check_arguments_if(char **arg, char *buf, t_hist *hist, int len)
{
	int	len_arg;

	if (NULL == *arg)
	{
		*arg = malloc(sizeof(char) * (len + 1));
		if (!*arg)
			return (1);
		ft_strlcpy(*arg, buf, len + 1);
	}
	else
	{
		len_arg = ft_strlen(*arg);
		*arg = ft_realloc(*arg, len_arg + len + 1);
		if (!*arg)
			return (1);
		ft_strlcat(*arg, buf, len_arg + len + 1);
	}
	return (0);
}

static int	check_arguments_realloc(char **arg, char *buf, t_pars *pa, \
t_hist *hist)
{
	int	len;
	int	len_arg;

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
		return (0);
	}
	return (1);
}

int	take_argument_for_pre_pars(char **line, t_pars *pa, t_hist *hist, int ret)
{
	char	*arg;
	t_pars	s;

	ft_bzero(&s, sizeof(t_pars));
	ret = check_semicolon_and_syntax(*line, &s, 0, 0);
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
		arg = pars_argument_before_semicolon(line, pa, 0);
		if (arg == NULL)
			return (1);
		pre_pars(arg, pa);
	}
	just_freestr_null(line);
	return (0);
}

int	pre_pars_branching(t_pars *pa, t_hist *hist, int ret, int check)
{
	char	buf[2049];

	ft_bzero(&buf, sizeof(buf));
	ret = read(0, buf, 2048);
	while (ft_strcmp(buf, "\n"))
	{
		check = check_esc_char(buf, hist, ret, pa);
		if (check == 2)
			return (0);
		if (!check && check_array_is_ascii(buf))
		{
			pa->tmp_flag = check_arguments_realloc(&hist->left, buf, pa, hist);
			if (0 == pa->tmp_flag)
				break ;
			else if (pa->tmp_flag < 0)
				return (1);
		}
		ft_bzero(&buf, sizeof(buf));
		ret = read(0, buf, 2048);
	}
	if (add_history_line(hist, buf))
		if (take_argument_for_pre_pars(&hist->left, pa, hist, 0))
			return (0);
	return (0);
}
