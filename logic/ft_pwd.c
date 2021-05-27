#include "header.h"

int	ft_pwd(t_bin *bin)
{
	getcwd(bin->pwd, PATH_MAX);
	ft_puts(bin->pwd);
	return (0);
}
