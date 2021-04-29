#include "header.h"

// копирование массива в листы
void copy_to_list(t_bin *bin)
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

void list_puts(t_list *lst)
{
	while(lst->next)
	{
		ft_puts(lst->content);
		lst = lst->next;
	}
	ft_puts(lst->content);
}
// export with lists
void ft_export(t_bin *bin)
{
	copy_to_list(bin);
	list_puts(bin->export);
}