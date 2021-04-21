#include "libft.h"

void 			ft_free_massive(char **mass)
{
	int			i;

	i = -1;
	if (NULL != mass)
	{
		while (mass[++i] != NULL)
		{
			free(mass[i]);
			mass[i] = NULL;
		}
		free(mass);
		mass = NULL;
	}
}