#include "header.h"

void	ft_check_malloc(char *str)
{
	if (!str)
		exit(errno);
}

int	type_of_redirect(char *str, int i)
{
	if (str[i] == '<')
		return (1);
	if (str[i] == '>' && str[i + 1] == '>')
		return (2);
	if (str[i] == '>')
		return (1);
	return (0);
}
