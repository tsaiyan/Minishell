#include "header.h"

//static int 		check_dollar_quest(char *curr_arg, t_pars *pa)
//{
//
//}

static char		*take_arg(char *curr_arg)
{
	char 		*ret;
	char 		buf[1];
	int 		len;

	len = 0;
	while (*curr_arg && *curr_arg != ';' && *curr_arg != ' ' && \
	*curr_arg != '\t')
	{

	}


}

int 			check_envp(char **curr_arg, t_pars *pa)
{
	char		*arg;

	if (pa->quot_flag == 2)
		return (0);
	if (!pa->envp)
		return (write_error(CANT_ACCESS_ENVP, pa->s));
//	if (*curr_arg[1] == '?' || ft_isdigit(*curr_arg[1]))
//		return (check_dollar_quest(*curr_arg, pa));
	arg = take_arg(*curr_arg);


}