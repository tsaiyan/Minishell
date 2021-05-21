#include "header.h"

int	ft_env(t_bin *bin)
{
	int	i;

	i = 0;
	if (!bin->envp_lst)
		bin->envp_lst = arr_to_dlist(bin->envp);
	print_list(bin->envp_lst, 2);
	return (0);
}
