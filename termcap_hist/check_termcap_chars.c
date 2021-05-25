#include "header.h"

static int	check_other_esc_char2(char *buf, t_hist *hist)
{
	if (!ft_strcmp(buf, "\e[H"))
		return (home_key(hist));
	else if (!ft_strcmp(buf, "\e[F"))
		return (end_key(hist));
	else if ((!ft_strcmp(buf, "\e")))
		return (1);
	return (0);
}

static int	check_other_esc_char(char *buf, t_hist *hist)
{
	if (!ft_strcmp(buf, "\t"))
		return (1);
	else if (!ft_strcmp(buf, "\177"))
		return (backspace_key(hist));
	else if (!ft_strcmp(buf, "\e[3~"))
		return (del_key(hist));
	else if (!ft_strcmp(buf, "\4"))
		return (eof_char(hist));
	else if (!ft_strcmp(buf, "\3"))
		return (ctrlc_char(hist));
	else if ((!ft_strcmp(buf, "\28")))
		return (1);
	return (check_other_esc_char2(buf, hist));
}

int	check_esc_char(char *buf, t_hist *hist, int len)
{
	if (!ft_strcmp(buf, "\e[D"))
		return (left_arrow(buf, len, hist, NULL));
	else if (!ft_strcmp(buf, "\e[C"))
		return (right_arrow(buf, len, hist));
	else if (!ft_strcmp(buf, "\e[A"))
		return (up_arrow(hist, 0));
	else if (!ft_strcmp(buf, "\e[B"))
		return (down_arrow(hist));
	else
		return (check_other_esc_char(buf, hist));
}
