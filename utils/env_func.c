#include "header.h"

static char		*take_arg(char *curr_arg)
{
	char 		*ret;
	int 		len;

	len = 0;
	while (*curr_arg && )
}

int 			check_envp(char *curr_arg, t_pars *pa)
{
	char		*arg;

	if (pa->quot_flag == 2)
		return (0);
	if (!pa->envp)
		return (write_error(CANT_ACCESS_ENVP, pa->s));

}