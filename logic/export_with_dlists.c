#include "header.h"

static t_mylst *my_lst_new(char *str)
{
	t_mylst *new_lst;

	new_lst = malloc(sizeof(t_mylst));
	if (!new_lst)
		exit(errno);
	new_lst->content = str;
	new_lst->next = NULL;
	new_lst->prev = NULL;
	return(new_lst);
}

static t_mylst *my_lst_last(t_mylst *current)
{
	while (current->next)
		current = current->next;
	return (current);
}

static void my_lst_add_back(t_mylst *start, t_mylst *add)
{
	t_mylst *last;

	last = my_lst_last(start);
	last->next = add;
	add->prev = last;
}

static void print_list(t_mylst *start)
{
	ft_puts("");
	while(start)
	{
		ft_puts(start->content);
		start = start->next;
	}
}

static void	arr_to_dlist(t_bin *bin)
{
	t_mylst *start;
	t_mylst *new_lst;
	int i;

	i = 1;
	start = my_lst_new(bin->envp[0]);
	while (bin->envp[i])
	{
		new_lst = my_lst_new(bin->envp[i]);
		my_lst_add_back(start, new_lst);
		i++;
	}
	print_list(start);
}

void ft_export(t_bin *bin)
{
	arr_to_dlist(bin);
}