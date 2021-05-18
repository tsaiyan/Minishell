#include "header.h"

char    **ft_del_index_in2massive(char **old, int index)
{
	int	len;
	char **new;
	int i;
	int j;

	len = ft_massive_len(old);
	if (len == index)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * len);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (++i != len)
	{
		if (i == index)
			free(old[i]);
		else
			new[++j] = old[i];
	}
	new[len] = NULL;
	free(old);
	return (new);
}