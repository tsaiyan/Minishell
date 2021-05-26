#include "header.h"

// check already exists key and change value

int	already_exist_key(t_mylst *current, t_mylst *add)
{
	char	*cur;

	while (current)
	{
		if (add->dollar && ft_strcmp(current->key, add->value) == 0)
		{
			free(add->value);
			add->value = current->value;
		}
		if (ft_strcmp(current->key, add->key) == 0 && !add->equal)
			return (free_my_lst(add));
		else if (ft_strcmp(current->key, add->key) == 0 && add->equal)
		{
			cur = current->value;
			plus_func(add, current);
			free_already_exist_key(add, current, cur);
			current->equal = 1;
			return (1);
		}
		current = current->next;
	}
	return (0);
}

// make new list: check += and $

t_mylst	*my_lst_new(char *str)
{
	t_mylst	*new_lst;
	char	*split_str;

	new_lst = ft_calloc(sizeof(t_mylst), 1);
	if (!new_lst)
		exit(errno);
	split_str = ft_strchr(str, '=');
	if (split_str != NULL)
	{
		if (*(split_str - 1) == '+')
		{
			new_lst->key = ft_strdup_chr(str, '+');
			new_lst->plus = 1;
			new_lst->value = ft_strdup(split_str + 1);
		}
		else
		{			
			new_lst->key = ft_strdup_chr(str, '=');
			new_lst->value = ft_strdup(split_str + 1);
		}
		new_lst->equal = 1;
	}
	else
		new_lst->key = ft_strdup(str);
	return (new_lst);
}

// check += + and other

int	check_plus(char *str)
{
	char	*plus;
	int		i;

	i = 0;
	plus = ft_strchr(str, '+');
	if (plus && ((*(plus + 1)) != '=') && ((*(plus - 1)) != '='))
	{
		command_error(str, 2);
		return (-1);
	}
	if (plus)
		return (1);
	return (0);
}

// list to envp

void	list_to_envp(t_bin *bin)
{
	char	**new_envp;
	t_mylst	*lst;
	int		i;
	char	*dom;

	i = 0;
	new_envp = ft_calloc(sizeof(char *), (my_lst_size(bin->envp_lst) + 1));
	if (!new_envp)
		exit(errno);
	lst = bin->envp_lst;
	while (lst)
	{
		new_envp[i] = ft_strjoin(lst->key, "=");
		dom = new_envp[i];
		new_envp[i] = ft_strjoin(new_envp[i], lst->value);
		free(dom);
		lst = lst->next;
		i++;
	}
	ft_free_massive(bin->envp);
	bin->envp = new_envp;
}

// MAIN FUNCTION	

void	ft_export(t_bin *bin, char **argv)
{
	int		i;
	t_mylst	*lst;

	i = 0;
	if (!argv[1])
	{
		sort_list(bin);
		print_list(bin->export, 1);
	}
	else
	{
		while (argv[++i])
		{
			if (check_plus(argv[i]) == -1)
				return ;
			if (!validate_export(argv[i]))
				command_error(argv[i], 2);
			lst = my_lst_new(argv[i]);
			my_lst_add_back(bin->export, lst);
			if (lst->equal)
				my_lst_add_back(bin->envp_lst, my_lst_new(bin->argv[i]));
		}
		sort_list(bin);
		list_to_envp(bin);
	}
}
