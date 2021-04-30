#include "header.h"

// make new list

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

// find last list

static t_mylst *my_lst_last(t_mylst *current)
{
	while (current->next)
		current = current->next;
	return (current);
}

// add list to back

static void my_lst_add_back(t_mylst *start, t_mylst *add)
{
	t_mylst *last;

	last = my_lst_last(start);
	last->next = add;
	add->prev = last;
}

// print lists

static void print_list(t_mylst *start)
{
	ft_puts(NULL);
	while(start)
	{
		ft_putstr("declare -x ");
		ft_puts(start->content);
		start = start->next;
	}
}

// copy envp to double lists

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
	bin->export = start;
	
}

static void swap_list(t_mylst *first, t_mylst *second)
{
	t_mylst *prev_first;

	prev_first = first->prev;
	first->next = second->next;
	first->prev = second;
	second->prev = prev_first;
	second->next = first;
}
// find head of list

t_mylst *find_head(t_mylst *lst)
{
	while (lst->prev)
		lst=lst->prev;
	return(lst);
}

// sorting A to z

static void sort_list(t_bin *bin)
{
	int flag = 1;
	t_mylst *start;
	t_mylst *next;
	t_mylst	*ret;

	ret = bin->export;
	int i = 0;

	while(flag)
	{
		flag = 0;
		start = bin->export;
		while (start && start->next)
		{
			next = start->next;
			if (ft_strcmp(start->content, next->content) > 0)
			{
				swap_list(start, next);
				flag = 1;
			}
			start = start->next;
		}
	}
	bin->export = find_head(ret);
}
// main function

void ft_export3(t_bin *bin)
{
	arr_to_dlist(bin);
	sort_list(bin);
	print_list(bin->export);
}