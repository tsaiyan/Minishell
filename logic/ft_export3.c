#include "header.h"

// swap value and key func

void	swap_list(t_mylst *start, t_mylst *next)
{
	char	*buf_value;
	char	*buf_key;
	int		buf_equal;

	buf_equal = start->equal;
	buf_value = start->value;
	buf_key = start->key;
	start->value = next->value;
	start->key = next->key;
	start->equal = next->equal;
	next->key = buf_key;
	next->value = buf_value;
	next->equal = buf_equal;
}

// sorting A to z by swap key and value in lists

void	sort_list(t_bin *bin)
{
	int		flag;
	t_mylst	*start;
	t_mylst	*next;

	flag = 1;
	while (flag)
	{
		flag = 0;
		start = bin->export;
		if (!start)
			return ;
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

// validator

int	validate_export(char *str)
{
	char	b;

	b = str[0];
	if (b < 65 || b > 122)
		return (0);
	if (b < 97 && b > 90 && b != '_')
		return (0);
	if (b > 57 && b < 65)
		return (0);
	return (1);
}

// print lists

void	print_list(t_mylst *start, int flag)
{
	while (start)
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
	while (start && str[i])
	{
		new_lst = my_lst_new(str[i]);
		my_lst_add_back(NULL, start, new_lst);
		i++;
	}
	return (start);
}
