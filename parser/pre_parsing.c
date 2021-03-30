#include "header.h"

int 				pre_pars_branching(char *envp[])
{
	int 			i;
	int				ret;
	char 			buf[1000];

	i = 10;
//	buf = ft_calloc(sizeof(char), i);
	while (0 < (ret = read(0, buf, i)))
	{
		printf("%s", buf);
	}
	if (ret == -1)
		ft_errors()
	return (0);
}