#include "header.h"

void	free_already_exist_key(t_mylst *add, t_mylst *current, char *cur)
{
	if (cur)
		free(cur);
	if (!add->plus)
		current->value = add->value;
	free(add->key);
	free(add);
}

// add list to back

t_mylst	*my_lst_add_back(t_mylst *start, t_mylst *add)
{
	t_mylst	*last;

	if (!already_exist_key(start, add))
	{	
		last = my_lst_last(start);
		last->next = add;
		add->prev = last;
		add->next = NULL;
		return (add);
	}
	return (NULL);
}

void	plus_func(t_mylst *add, t_mylst *current)
{
	if (add->plus)
	{
		current->value = ft_strjoin(current->value, add->value);
		free(add->value);
		add->value = NULL;
	}
}
