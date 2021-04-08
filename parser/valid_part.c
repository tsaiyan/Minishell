#include "header.h"

static int	reverse_redirect(char *line, int *i)
{
	int		flag;

	flag = 0;
	if (line[*i + 1] == '<')
		return (MULTI_LINE_COMMAND);
	if (ft_isdigit(line[*i - 1]))
		return (SYNTAX_ERROR);
	*i += 1;
	while (line[*i] != ';' && line[*i] != 0 && line[*i] != '|' && \
	line[*i] !=	'>')
	{
		if (ft_isprint(line[*i]) && !ft_isspace(line[*i]))
			flag = 1;
		*i += 1;
	}
	return ((flag == 0) * SYNTAX_ERROR_PREPARS);
}

static int forward_redirect(char *line, int *i, int *ori)
{
	int 	flag;

	flag = 0;
	*i += 1;
	if (line[*i] == '>')
	{
		if (line[*i + 1] == '>')
			return (MULTI_LINE_COMMAND);
		*i += 1;
		*ori += 1;
	}
	if (*i != 1 && *i != 0)
		if (ft_isdigit(line[*i - 2]))
			return (SYNTAX_ERROR);
	while (line[*i] != ';' && line[*i] != 0 && line[*i] != '|' && \
	line[*i] !=	'>')
	{
		if (ft_isprint(line[*i]) && !ft_isspace(line[*i]))
			flag = 1;
		*i += 1;
	}
	return ((flag == 0) * SYNTAX_ERROR_PREPARS);
}

int 		valid_redirects(char *line, int *i)
{
	int 	tmp;
	int 	ret;

	tmp = *i;
	if (line[tmp] == '<')
	{
		ret = reverse_redirect(line, &tmp);
		if (ret < 0)
			return (ret);
	}
	if (line[tmp] == '>')
	{
		ret = forward_redirect(line, &tmp, i);
		if (ret < 0)
			return (ret);
	}
	return (0);
}