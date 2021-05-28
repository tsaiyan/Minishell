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

void	change_head_in_bin(t_bin *bin, t_mylst	*lst_to_unset, int flag)
{
	if (!lst_to_unset->prev && flag == 1)
	{
		if (bin->export)
		{
			bin->export = bin->export->next;
			bin->export->prev = NULL;
		}
	}
	if (!lst_to_unset->prev && flag == 2)
	{
		if (bin->envp_lst)
		{
			if (bin->envp_lst->next)
			{
				bin->envp_lst = bin->envp_lst->next;
				bin->envp_lst->prev = NULL;
			}
		}
	}
}

void	ft_find_and_delete(t_bin *bin, t_mylst *envexp, char *argv, int flag)
{
	t_mylst	*lst_to_unset;

	lst_to_unset = find_lst(envexp, argv);
	if (lst_to_unset)
	{
		if (!lst_to_unset->next && !lst_to_unset->prev && flag == 2)
			bin->envp_lst = NULL;
		if (!lst_to_unset->next && !lst_to_unset->prev && flag == 1)
			bin->export = NULL;
		if (lst_to_unset->prev)
			lst_to_unset->prev->next = lst_to_unset->next;
		if (lst_to_unset->next)
			lst_to_unset->next->prev = lst_to_unset->prev;
		change_head_in_bin(bin, lst_to_unset, flag);
		free_my_lst(lst_to_unset);
	}
}

void	ft_unset(t_bin *bin, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		ft_find_and_delete(bin, bin->export, argv[i], 1);
		ft_find_and_delete(bin, bin->envp_lst, argv[i], 2);
		i++;
	}
	list_to_envp(bin);
}
