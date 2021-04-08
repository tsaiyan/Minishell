#include "header.h"

static int semicolon_len(char *s)
{
	int 	len;

	len = 0;
	while (s[len] != ';' && s[len] != 0)
		len++;
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
	arg = ft_calloc(sizeof(char), len + 1);
	if (NULL == arg)
		return (NULL);
	ft_strlcpy(arg, *line, len + 1);
	tmp = find_substr_in_str_and_replace(arg, *line, "", &i);
	free(*line);
	*line = tmp;
	return (arg);
}