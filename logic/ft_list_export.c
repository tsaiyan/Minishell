#include "header.h"

// copy massive to lists
void copy_envp_to_list(t_bin *bin)
{
	t_list *start;
	t_list *lst;
	int i;

	i = 1;
	lst = ft_lstnew(&bin->envp[0]);
	ft_puts(lst->content);
	start = lst;
	while (bin->envp[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(bin->envp[i]));
		lst = lst->next;
		i++;
	}
	bin->export = start;
}

// puts from list
void list_puts(t_list *lst)
{
	while(lst)
	{
		ft_puts(lst->content);
		lst = lst->next;
	}
}

// проверка на существование строки перед добавлением
void ft_add_newline(t_bin *bin, char *str)
{
	t_list *lst;

	lst = bin->export;
	while (lst)
	{
		if (!ft_strcmp(lst->content, str))
			return;
		lst = lst->next;
	}
	// запись
	ft_lstadd_back(&bin->export, ft_lstnew(str));
}

// export with lists
void ft_export(t_bin *bin)
{
	int i;

	i = 1;
	if (bin->argv[1] == 0)
		ft_print_export(bin);
	else
	{
		if (!(bin->export))
			copy_envp_to_list(bin);
		while(bin->argv[i])
		{
			 ft_add_newline(bin, bin->argv[i]);
			i++;
		}
		list_puts(bin->export);
	}
}