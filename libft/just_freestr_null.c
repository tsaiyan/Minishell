#include "libft.h"

void	just_freestr_null(char **str)
{
	free(*str);
	*str = NULL;
}
