#include "header.h"

int					check_exit(int flag)
{
	return (flag);
}

int 				main(int argc, char **argv,char *envp[])
{
	int 			flag;

	flag = 0;
	while (!(check_exit(flag)))
	{
		printf("COLOR_BLUEminishell:COLOR_RESET");
		flag = pre_pars_branching(envp);
	}
	return (1);
}