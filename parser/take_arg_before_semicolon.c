#include "header.h"

static int	check_redirects_pipes_semicolons(char t, char *line)
{
	int	i;

	i = 0;
	if (t == ';')
		return (ERROR_UNEXPECTED_SEMICOLON);
	if (t == '|')
		return (ERROR_UNEXPECTED_PIPE);
	return (valid_redirects(line, &i));
}

int	check_semicolon_and_syntax(char *line, t_pars *pa, int i, int ret)
{
	if (line[i] == ';' || line[i] == '|' || line[i] == '<' || line[i] == '>')
		return (check_redirects_pipes_semicolons(line[i], line));
	if (line[i] == S_QUOT || line[i] == W_QUOT)
		check_quotes_subst(line, pa, &i);
	while (line[++i] != 0)
	{
		ret = check_semicolon_and_syntax2(line, pa, &i, 0);
		if (0 > ret)
			return (ret);
	}
	return (0);
}
//validate syntax errors
