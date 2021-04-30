#include "header.h"

// void	swap_lists(t_bin *first, t_bin *second)
// {
// 	t_list *temp;

// 	temp = first->next;

// }

//if (*((char*)lst_next->content) > *((char*)lst_current->content))
//strcmp

void	ft_sort_list(t_bin *bin)
{
	t_list *lst_current;
	t_list *lst_next;
	t_list *next_next;
	t_list *temp_current;
	t_list *start;
	int flag = 1;

	start = bin->export;
	lst_current = bin->export;
	while (flag)
	{
		flag = 0;
		lst_current = start;
		while(lst_current)
		{
			lst_next = lst_current->next;
			//ft_print_export(bin);
			if (lst_next)
				if (ft_strcmp((char*)lst_current->content, (char*)lst_next->content) > 0)
				{
					//ft_puts((char*)lst_current->content);
					//ft_puts((char*)lst_next->content);
					next_next = lst_next->next;
					temp_current = lst_current;
					lst_current = lst_next;
					lst_current->next = temp_current;
					lst_next = temp_current;
					temp_current->next = next_next->next;
					flag = 1;
				}
			//ft_puts((char*)lst_current->content);
			lst_current = lst_current->next;
		}
	}
	bin->export = start;
}