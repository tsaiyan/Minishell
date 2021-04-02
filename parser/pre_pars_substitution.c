#include "header.h"

static void		check_quotes_subst(char *arg, t_pars *pa, int *i)
{

}

static void		check_spaces(char *arg, t_pars *pa, int *i)
{

}

static int		check_slashes(const char *arg, t_pars *pa, int *i)
{
	if (arg[*i] == '\\' && arg[*i + 1] != '\0')
	{
		*i += 1;
		return (0);
	}
	return ((arg[*i + 1] == '\0') * 1);
}

int check_chars_subst(char **arg, t_pars *pa, int *i)
{
	if (arg[0][*i] == ' ')
		check_spaces(*arg, pa, i);
	else if (arg[0][*i] == '\\' || arg[0][*i] == '/')
	{
		if (check_slashes(*arg, pa, i))
			return (1);
	}
	else if (arg[0][*i] == S_QUOT || arg[0][*i] == W_QUOT)
		check_quotes_subst(*arg, pa, i);
	else if (arg[0][*i] == '$')
	{
		if
	}
}