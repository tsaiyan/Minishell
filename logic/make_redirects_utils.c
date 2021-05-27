#include "header.h"

void	ft_check_malloc(char *str)
{
	if (!str)
		exit(errno);
}

int	type_of_redirect(char *str, int i)
{
	if (str[i] == RVRS_RDRCT)
		return (1);
	if (str[i] == FRWRD_RDRCT && str[i + 1] == FRWRD_RDRCT)
		return (2);
	if (str[i] == FRWRD_RDRCT)
		return (1);
	return (0);
}
