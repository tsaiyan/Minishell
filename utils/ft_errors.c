#include "header.h"

void 			ft_errors(int code)
{
	write(2, "minishell:", 10);
	strerror(errno);
}