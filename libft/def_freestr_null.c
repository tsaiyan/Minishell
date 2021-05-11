#include "libft.h"

void	def_freestr_null(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}
