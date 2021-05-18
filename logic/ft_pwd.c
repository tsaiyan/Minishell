#include "header.h"

int	ft_pwd(t_bin *bin)
{
	char dir[PATH_MAX];
	getcwd(dir, PATH_MAX);
	ft_nputs(dir);
	return 0;
}