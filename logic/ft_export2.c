#include "header.h"

// lst size

int	my_lst_size(t_mylst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// free all list | ret=1 for norminette in already_exist_key

int	free_my_lst(t_mylst *lst)
{
	if (lst)
	{
		if (lst->key)
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
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

// find head of list

t_mylst	*find_head(t_mylst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
