#include "header.h"

// lst size

int	my_lst_size(t_mylst *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst= lst->next;
		i++;
	}
	return (i);
}

// free all list | ret=1 for norminette in already_exist_key

int	free_my_lst(t_mylst *lst)
{
	if (lst)
	{
		if(lst->key)
			free(lst->key);
		if (lst->value)
			free(lst->value);
		free(lst);
		lst = NULL;
	}
	return (1);
}

// dup without '='

char	*ft_strdup_chr(char *str, char end)
{
	size_t	len;
	char	*res;

	len = 0;
	while (str[len] != end)
		len++;
	res = (char *)ft_calloc(sizeof(char), ++len);
	if (res == NULL)
		exit(errno);
	return ((char *)ft_memcpy(res, str, len - 1));
}

// find last list

t_mylst	*my_lst_last(t_mylst *current)
{
	while (current->next)
		current = current->next;
	return (current);
}

// find head of list

t_mylst *find_head(t_mylst *lst)
{
	while (lst->prev)
		lst=lst->prev;
	return (lst);
}

// swap value and key func

void	swap_list(t_mylst *start, t_mylst *next)
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

void sort_list(t_bin *bin)
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