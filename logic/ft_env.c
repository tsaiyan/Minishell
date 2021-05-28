#include "header.h"

void	print_env(t_mylst *start, int flag)
{
	while (start)
	{
		if (flag == 1)
			ft_putstr("declare -x ");
		ft_putstr(start->key);
		if (start->equal)
		{
			ft_putstr("=");
			ft_putstr(start->value);
			ft_putstr("");
		}
		ft_puts(NULL);
		start = start->next;
	}
}

int	ft_env(t_bin *bin)
{
	int	i;

	i = 0;
	if (!bin->envp_lst)
		bin->envp_lst = arr_to_dlist(bin->envp);
	print_env(bin->envp_lst, 2);
	return (0);
}
