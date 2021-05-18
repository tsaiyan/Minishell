#include "header.h"

static int check_pipe(char *line, t_pars *pa, int *i)
{
	int 	tmp;
	int 	flag;

	tmp = *i - 1;
	flag = 0;
	while (tmp != -1 && line[tmp] != '|')
	{
		if (ft_isprint(line[tmp]) && !ft_isspace(line[tmp]))
				flag = 1;
		if (line[tmp] == ';' && line[tmp - 1] == '\\')
			break ;
		tmp--;
	}
	if (!flag)
		return (ERROR_UNEXPECTED_PIPE);
	tmp = *i;
	while (line[++tmp] != 0)
	{
		if (ft_isprint(line[tmp]) && !ft_isspace(line[tmp]))
				flag = 2;
		if (line[tmp] == ';' && line[tmp - 1] == '\\')
			break ;
	}
	if (flag != 2)
		return (MULTI_LINE_COMMAND);
	return (0);
}

static int check_semicolon(char *line, t_pars *pa, int *i)
{
	int 	tmp;

	tmp = *i - 1;
	while (tmp != -1 && line[tmp] != ';')
	{
		if (ft_isprint(line[tmp]))
			if (!ft_isspace(line[tmp]))
				return (1);
		tmp--;
	}
	return (ERROR_UNEXPECTED_SEMICOLON);
}

static int check_redirects_pipes_semicolons(char t, char *line)
{
	int 		i;

	i = 0;
	if (t == ';')
		return (ERROR_UNEXPECTED_SEMICOLON);
	if (t == '|')
		return (ERROR_UNEXPECTED_PIPE);
	return (valid_redirects(line, &i));
}

int check_semicolon_and_syntax(char *line, t_pars *pa)
{
	int 		i;
	int 		ret;

	i = 0;
	if (line[i] == ';' || line[i] == '|' || line[i] == '<' || line[i] == '>' )
			return (check_redirects_pipes_semicolons(line[i], line));
	if (line[i] == S_QUOT || line[i] == W_QUOT)
		check_quotes_subst(line, pa, &i);
	while (line[++i] != 0)
	{
		if ((line[i] == S_QUOT || line[i] == W_QUOT) && line[i - 1] != '\\')
			check_quotes_subst(line, pa, &i);
		if (line[i] == ';' && line[i - 1] != '\\' && pa->quot_flag == 0)
			if (0 > (check_semicolon(line, pa, &i)))
				return (ERROR_UNEXPECTED_SEMICOLON);
		if (line[i] == '|' && line[i - 1] != '\\' && pa->quot_flag == 0)
		{
			ret = check_pipe(line, pa, &i);
			if (0 > ret)
				return (ret);
		}
		if ((line[i] == '>' || line[i] == '<') && line[i - 1] != '\\' && \
		pa->quot_flag == 0)
		{
			ret = valid_redirects(line, &i);
			if (0 > ret)
				return (ret);
		}
	}
	return (0);
}

//validate syntax errors

