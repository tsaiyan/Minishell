#include "header.h"

int ft_pwd()
{
	char	dir[PATH_MAX];

	getcwd(dir, PATH_MAX);
	ft_puts(dir);
	return (0);
}
