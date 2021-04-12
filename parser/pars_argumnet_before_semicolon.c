#include "header.h"

static int semicolon_len(char *s)
{
	int 	len;
	t_pars		t;

	len = 0;
	t.quot_flag = 0;
	if (s[len] == ';')
		return (0);
	if (s[len] == '\'' || s[len] == '\"')
		check_quotes_subst(s, &t, &len);
	len++;
	while (0 == ((s[len - 1] != '\\' && s[len] == ';') && t.quot_flag == 0) &&
	s[len] != 0)
	{
		if (s[len - 1] != '\\' && (s[len] == '\'' || s[len] == '\"'))
			check_quotes_subst(s, &t, &len);
		len++;
	}
	return (len);
}

char *pars_argument_before_semicolon(char **line, t_pars *pa)
{
	int 	len;
	char 	*arg;
	char	*tmp;
	int		i;

	i = 0;
	len = semicolon_len(*line) + 1;
	if (len == 0)
	{
		write_error(ERROR_UNEXPECTED_SEMICOLON, *line);
		return (NULL);
	}
	arg = ft_calloc(sizeof(char), len + 1);
	if (NULL == arg)
		return (NULL);
	ft_strlcpy(arg, *line, len + 1);
	tmp = find_substr_in_str_and_replace(arg, *line, "", &i);
	free(*line);
	*line = tmp;
	i = ft_strlen(arg);
	i--;
	tmp = find_substr_in_str_and_replace(";", arg, "", &i);
	if (tmp == NULL)
		return (arg);
	free(arg);
	return (tmp);
}