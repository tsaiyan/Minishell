#include "header.h"

// check already exists key and change value

int	already_exist_key(t_mylst *current, t_mylst *add)
{
	char *cur;

	while (current)
	{
		if (add->dollar && ft_strcmp(current->key, add->value) == 0)
			{
				free(add->value);
				add->value = current->value;

			}
		if (ft_strcmp(current->key, add->key) == 0 && !add->equal)
		{
			free_my_lst(add);
			return(1);
		}
		else if (ft_strcmp(current->key, add->key) == 0 && add->equal)
		{
			cur = current->value;
			if (add->plus)
				current->value = ft_strjoin(current->value, add->value);
			if (cur)
				free(cur);
			if (!add->plus)
				current->value = add->value;
			free(add->key);
			free(add);
			current->equal = 1;
			return (1);
		}
		current = current->next;
	}
	return (0);
}

// make new list: check += and $

static t_mylst	*my_lst_new(char *str)
{
	t_mylst	*new_lst;
	char	*split_str;

	new_lst = calloc(sizeof(t_mylst), 1);
	if (!new_lst)
		exit(errno);
	split_str = ft_strchr(str, '=');
	if (split_str != NULL)
	{
		if (*(split_str - 1) == '+')
		{
			new_lst->key = ft_strdup_chr(str, '+');
			new_lst->plus = 1;
		}
		else
			new_lst->key = ft_strdup_chr(str, '=');
		if (*(split_str + 1) == '$')
		{
			new_lst->value = ft_strdup(split_str + 2);
			new_lst->dollar = 1;
		}
		else
			new_lst->value = ft_strdup(split_str + 1);
		new_lst->equal = 1;
	}
	else
		new_lst->key = ft_strdup(str);
	return(new_lst);
}

// add list to back

static t_mylst	*my_lst_add_back(t_mylst *start, t_mylst *add)
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

void	print_list(t_mylst *start, int flag)
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

t_mylst	*arr_to_dlist(char **str)
{
	t_mylst	*start;
	t_mylst	*new_lst;
	int		i;

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



// check += + and other

int check_plus(char *str)
{
	char *plus;
	int i;

	i = 0;
	plus=ft_strchr(str, '+');
	if (plus && ((*(plus + 1)) != '=') && ((*(plus - 1)) != '='))
	{
		ft_putstr("\nbash: export: `");
		ft_putstr(str);
		ft_puts("': not a valid identifier");
		return(-1);
	}
	if (plus)
		return (1);
	return (0);
}

// // put from export $value

// char *put_value_from_export(t_bin *bin, char *str)
// {
// 	char *ret;
// 	t_mylst *lst;
// 	char *dom;

// 	lst = bin->export;
// 	while(lst)
// 	{
// 		dom = ret;
// 		if (ft_strcmp(lst->key, str) == 0)
// 			ret = ft_strjoin(ret, lst->value);
// 		lst=lst->next;
// 		if (dom)
// 			free(dom);
// 	}
// 	return(ret);
// }

// // check $ in argv
// char *check_dollar(t_bin *bin, char *str)
// {
// 	int i = 0;
// 	int j = 0;
// 	char buf[1000];
// 	char *ret;

// 	while(str[i])
// 	{
// 		if (str[i] == '$')
// 			while (str[i] != 0 || str[i] != '$' || str[i] != ' ')
// 			{
// 				buf[j] = str[i];
// 				j++;
// 				buf[j] = '\0';
// 				ret = put_value_from_export(bin, buf);
// 				i++;
// 			}
// 			j = 0;
// 			//проверка на пробел нужна чтобы делать export b="$PATH $PATH"
// 			// if (str[i] == ' ')
// 			// 	buf[j++] = 32;
// 		i++;
// 	}
// }

int	my_lst_size(t_mylst *lst)
{
	int i;

	i = 0;
	while(lst)
	{
		lst= lst->next;
		i++;
	}
	return (i);
}

// list to envp
void	list_to_envp(t_bin *bin)
{
	char **envp;
	t_mylst *lst;
	int i;
	char *dom;

	i = 0;
	envp = ft_calloc(sizeof(char*), (my_lst_size(bin->envp_lst) + 1));
	if (!envp)
		exit(errno);
	lst = bin->envp_lst;
	while(lst)
	{
		//free(bin->envp[i]);
		bin->envp[i] = ft_strjoin(lst->key, "=");
		dom = envp[i];
		bin->envp[i] = ft_strjoin(envp[i], lst->value);
		free(dom);
		lst = lst->next;
		i++;
	}
}


// MAIN FUNCTION	

void	ft_export(t_bin *bin)
{
	int		i;
	t_mylst	*lst;
	char	*dollar;

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
			// dollar = check_dollar(bin, bin->argv[i]);
			// if (dollar)
			// 	{
			// 		free(bin-argv[i]);
			// 		bin->argv[i] = dollar;
			// 	}
			if (check_plus(bin->argv[i]) == -1)
				return;
			lst = my_lst_new(bin->argv[i]);
			my_lst_add_back(bin->export, lst);
			if(lst->equal)
				my_lst_add_back(bin->envp_lst, my_lst_new(bin->argv[i]));
			i++;
			write(1, "\n", 1);
		}
		sort_list(bin);
		list_to_envp(bin);
		print_list(bin->export, 1);
	}
 }
