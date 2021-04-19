#include "libft.h"

size_t		ft_massive_len(char **mass)
{
	int 	len;

	len = -1;
	if (mass == NULL)
		return (0);
	while (mass[++len] != NULL)
		;
	return (len);
}