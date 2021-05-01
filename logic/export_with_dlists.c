#include "header.h"

// free all list

void	free_my_lst(t_mylst *lst)
{
	if (lst)
	{
	if(lst->key)
		free(lst->key);
	if (lst->value)
		free(lst->value);
	free(lst);
	}

}
// check already exists key and change value

int	already_exist_key(t_mylst *current, t_mylst *add)
{
	while (current)
	{
		if (ft_strcmp(current->key, add->key) == 0 && !add->equal)
		{
			free_my_lst(add);
			return(1);
		}
		else if (ft_strcmp(current->key, add->key) == 0 && add->equal)
		{
			current->value = add->value;
			current->equal = 1;
			return (1);
		}
		current = current->next;
	}
	return (0);
}


// dup without '='

char	*ft_strdup_chr(char *str, char end)
{
	size_t	len;
	char	*res;

	len = 0;
	while(str[len] != end)
		len++;
	res = (char *)malloc(sizeof(char) * ++len);
	if (res == NULL)
		exit(errno);
	return ((char *)ft_memcpy(res, str, len - 1));
}

// make new list

static t_mylst *my_lst_new(char *str)
{
	t_mylst	*new_lst;
	char	*split_str;

	new_lst = calloc(sizeof(t_mylst), 1);
	if (!new_lst)
		exit(errno);
	split_str = ft_strchr(str, '=');
	if (split_str != NULL)
	{
		new_lst->value = (split_str + 1);
		new_lst->key = ft_strdup_chr(str, '=');
		new_lst->equal = 1;
	}
	else
		new_lst->key = str;
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

t_mylst *my_lst_add_back(t_mylst *start, t_mylst *add)
{
	t_mylst *last;

	if (!already_exist_key(start, add))
	{	
		last = my_lst_last(start);
		last->next = add;
		add->prev = last;
		add->next = NULL;
		return(add);
	}
	return (NULL);
}

// print lists

void print_list(t_mylst *start, int flag)
{
	ft_puts(NULL);
	while(start)
	{
		if (flag == 1)
			ft_putstr("declare -x ");
		ft_putstr(start->key);
		if (start->equal)
		{
			ft_putstr("=\"");
			ft_putstr(start->value);
			ft_putstr("\"");
		}
		ft_puts(NULL);
		start = start->next;
	}
}

// copy envp to double lists

t_mylst *arr_to_dlist(char **str)
{
	t_mylst *start;
	t_mylst *new_lst;
	int i;

	i = 1;
	start = my_lst_new(str[0]);
	while (str[i])
	{
		new_lst = my_lst_new(str[i]);
		my_lst_add_back(start, new_lst);
		i++;
	}
	return(start);
}

// find head of list

t_mylst *find_head(t_mylst *lst)
{
	while (lst->prev)
		lst=lst->prev;
	return(lst);
}

// swap value and key func

static void swap_list(t_mylst *start, t_mylst *next)
{
	char *buf_value;
	char *buf_key;

	buf_value = start->value;
	buf_key = start->key;
	start->value = next->value;
	start->key = next->key;
	next->key = buf_key;
	next->value = buf_value;
}

// sorting A to z by swap key and value in lists

static void sort_list(t_bin *bin)
{
	int		flag;
	t_mylst	*start;
	t_mylst	*next;

	flag = 1;
	while (flag)
	{
		flag = 0;
		start = bin->export;
		next = start->next;
		while (next)
		{
			if (ft_strcmp(start->key, next->key) > 0)
			{
				swap_list(start, next);
				flag = 1;
			}
			start = start->next;
			next = next->next;
		}
	}
}

// add list to envp

void	add_to_envp(t_bin *bin, t_mylst *lst)
{
	t_mylst *last_list;

	last_list = my_lst_last(bin->envp_lst);
	last_list->next = lst;
	lst->prev = last_list;
	lst->next = NULL;
}

// main function

void ft_export(t_bin *bin)
{
	int i;
	// t_mylst *lst_to_add_to_envp;
	// t_mylst *last_export;
	t_mylst *lst;

	i = 1;
	if (!bin->export)
		bin->export = arr_to_dlist(bin->envp);
	if (!bin->envp_lst)
		bin->envp_lst = arr_to_dlist(bin->envp);
	if (!bin->argv[1])
	{
		sort_list(bin);
		print_list(bin->export, 1);
	}
	else
	{
		while (bin->argv[i])
		{
			my_lst_add_back(bin->export, my_lst_new(bin->argv[i]));
			lst = my_lst_new(bin->argv[i]);
			if(lst->equal)
			my_lst_add_back(bin->envp_lst, my_lst_new(bin->argv[i]));
			i++;
		}
		sort_list(bin);
		print_list(bin->export, 1);
	}
 }

// main env function

int	ft_env(t_bin *bin)
{
   int i;

   i = 0;
   if (!bin->envp_lst)
  	 bin->envp_lst = arr_to_dlist(bin->envp);
   print_list(bin->envp_lst, 2);
   return 0;	
}