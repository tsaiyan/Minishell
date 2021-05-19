#include "header.h"

int	check_spaces_prep(char *cur_arg, t_pars *pa)
{
	if (pa->tmp_flag != 1 && !pa->quot_flag)
		pa->tmp_flag = 1;
	else if (pa->tmp_flag == 1 && !pa->quot_flag)
		*cur_arg = EMPTY_SPACE;
	return (0);
}
