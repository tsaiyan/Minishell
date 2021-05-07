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

	if (!bin->argv[1])
	{
		home_path = ft_get_value(bin->export, "HOME");
		ft_puts(NULL);
		ft_puts(home_path);
		return;
	}
	
	if (!home_path)
	{
		ft_puts("\nno home path");
		return;
	}
}