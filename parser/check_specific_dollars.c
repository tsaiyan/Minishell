#include "header.h"

int	check_specific_dollar(char **arg, t_pars *pa, int *i, char *str)
{
	char	*del;

	if (!ft_strcmp(str, "$$"))
	{
		pa->tmp = 2;
		return (1);
	}
	if (!ft_strcmp(str, "$?"))
	{
		del = ft_itoa(pa->b->exit_status);
		*arg = find_substr_in_str_and_replace(str, *arg, del, i);
		free(del);
		pa->tmp = 1;
		return (1);
	}
	if (ft_isdigit(str[1]))
	{
		*arg = find_substr_in_str_and_replace(str, *arg, "", i);
		return (1);
	}
	return (0);
}

int	check_specific_dollar2(char **arg, t_pars *pa, int *i, char *str)
{
	// if (arg[0][*i + 1] == '\t' || arg[0][*i + 1] == ' ' || arg[0][*i + 1] == '\0'\
	// || arg[0][*i + 1] == '$' || arg[0][*i + 1] == '-' || arg[0][*i + 1] == '+'\
	// || arg[0][*i + 1] == '/' || arg[0][*i + 1] == '=' || arg[0][*i + 1] == '%'\
	// || arg[0][*i + 1] == '~' || arg[0][*i + 1] == ',' || arg[0][*i + 1] == '.'\
	// || arg[0][*i + 1] == '%' || arg[0][*i + 1] == ':' || arg[0][*i + 1] == '{'\
	// || arg[0][*i + 1] == '}' || arg[0][*i + 1] == '[' || arg[0][*i + 1] == ']'\
	// || arg[0][*i + 1] == '%' || arg[0][*i + 1] == '^'
	// || arg[0][*i + 1] == '%' || arg[0][*i + 1] == '&')
	if (!ft_isalnum(arg[0][*i + 1]) && arg[0][*i + 1] != '_' && arg[0][*i + 1] != '?')
	{
		*i += 1;
		return (1);
	}
	return (0);
}