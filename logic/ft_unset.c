#include "header.h"

t_mylst	*find_lst(t_mylst *lst, char *key)
{
	while (lst)
	{
		if (!strcmp(lst->key, key))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_find_and_delete(t_bin *bin, t_mylst *envexp, char *argv)
{
	int		i;
	t_mylst	*lst_to_unset;

	i = 2;
	lst_to_unset = find_lst(envexp, argv);
	if (lst_to_unset)
	{
		if (lst_to_unset->prev)
		{
			lst_to_unset->prev->next = lst_to_unset->next;
			bin->export = find_head(lst_to_unset->prev);
			bin->envp_lst = find_head(lst_to_unset->prev);
			i--;
		}
		if (lst_to_unset->next)
		{
			lst_to_unset->next->prev = lst_to_unset->prev;
			bin->export = find_head(lst_to_unset->next);
			bin->envp_lst = find_head(lst_to_unset->next);
			i--;
		}
		if (i == 2)
		{
			bin->export = NULL;
			bin->envp_lst = NULL;
		}
		free_my_lst(lst_to_unset);
	}
}

void	ft_unset(t_bin *bin, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		ft_find_and_delete(bin, bin->export, argv[i]);
		ft_find_and_delete(bin, bin->envp_lst, argv[i]);
		i++;
	}
	list_to_envp(bin);
}
