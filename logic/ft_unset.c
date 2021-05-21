#include "header.h"

t_mylst	*find_lst(t_mylst *lst, char *key)
{
	while(lst)
	{
		if (!strcmp(lst->key, key))
			return(lst);
		lst = lst->next;
	}
	return(NULL);
}

void ft_find_and_delete(t_mylst *envexp, t_bin *bin, char *argv)
{
	int i;
	t_mylst *lst_to_unset;

	i = 0;
	lst_to_unset = find_lst(envexp, argv);
	if (lst_to_unset)
	{
		if(lst_to_unset->prev)
			lst_to_unset->prev->next=lst_to_unset->next;
		if (lst_to_unset->next)
			lst_to_unset->next->prev=lst_to_unset->prev;
		free_my_lst(lst_to_unset);
	}
}
void	ft_unset(t_bin *bin, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		ft_find_and_delete(bin->export, bin, argv[i]);
		ft_find_and_delete(bin->envp_lst, bin, argv[i]);
		i++;
	}
	list_to_envp(bin);
}