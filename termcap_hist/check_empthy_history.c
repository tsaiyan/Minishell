#include "header.h"

int check_empty_history(t_hist *hist, char *buf)
{
	if (*hist->left == 0 && *buf == '\n')
		return (1);
	return (0);
}