#include "libft.h"

size_t	ft_massive_len(char **mass)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	if (mass == NULL)
		return (0);
	while (mass[++i] != NULL)
		++len;
	return (len);
}
