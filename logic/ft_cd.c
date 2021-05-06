#include "header.h"

char	*ft_get_value(t_mylst *lst, char *key)
{
	while(lst)
	{
		if (strcmp(lst->key, key) == 0)
			return(lst->value);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_cd(t_bin *bin)
{
	char *home_path;

	home_path = ft_get_value(bin->export, "sdfdsf");
	if (!home_path)
	{
		
	}
}