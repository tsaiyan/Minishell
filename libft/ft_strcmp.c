#include "libft.h"

int 			ft_strcmp(const char *string1, const char *string2)
{
	int 		i;

	i = 0;
	while (string1[i] && string2[i])
	{
		if (string1[i] != string2[i])
			break ;
		i++;
	}
	return (string1[i] - string2[i]);
}