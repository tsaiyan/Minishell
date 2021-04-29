#include "header.h"
int	ft_pwd(t_bin *bin)
{
	char dir[1000];
	getcwd(dir, 1000);
	ft_nputs(dir);
	return 0;
}