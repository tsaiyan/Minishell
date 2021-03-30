#include "header.h"

int ft_errors(int code)
{
	write(2, "minishell:", 10);
	strerror(errno);
	return (code);
}