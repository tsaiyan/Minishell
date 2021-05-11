#include "libft.h"

int	ft_isspace(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\v' || ch == '\n' || ch == '\r')
		return (1);
	return (0);
}
