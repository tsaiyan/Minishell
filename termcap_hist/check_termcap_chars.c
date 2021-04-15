#include "header.h"

static int check_other_esc_char(char *buf, t_hist *hist, int len)
{
	return (0);
}

int check_esc_char(char *buf, t_hist *hist, int len)
{
	if (!ft_strcmp(buf, "\e[D"))
		left_arrow(buf, len);
	else if (!strcmp(buf, "\e[C"))
		right_arrow(buf, len);
	else if (!strcmp(buf, "\e[A"))
		up_arrow();
	else if (!strcmp(buf, "\e[B"))
		down_arrow();
	return (check_other_esc_char(buf, hist, len));
}