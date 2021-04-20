#include "header.h"

static int check_other_esc_char(char *buf, t_hist *hist, int len, char **env)
{
//	write(1, buf, len);
//	printf("%d", *buf);
	if (!ft_strcmp(buf, "\t"))
		return (1);
	else if (!ft_strcmp(buf, "\177"))
		return (backspace_key(buf, len, hist));
	else if (!ft_strcmp(buf, "\e[3~"))
		return (del_key(hist));
	else if (!ft_strcmp(buf, "\4"))
		return (eof_char(hist, env));
	return (0);
}

int check_esc_char(char *buf, t_hist *hist, int len, char **env)
{
//	printf("%d - %d - %d", buf[0], buf[1], buf[2]);
//	ft_putchar_fd(1, buf[0]);
//	ft_putchar_fd(1, buf[1]);
//	ft_putchar_fd(1, buf[2]);
	if (!ft_strcmp(buf, "\e[D"))
		return (left_arrow(buf, len, hist));
	else if (!ft_strcmp(buf, "\e[C"))
		return (right_arrow(buf, len, hist));
	else if (!ft_strcmp(buf, "\e[A"))
		return (up_arrow());
	else if (!ft_strcmp(buf, "\e[B"))
		return (down_arrow());
	else
		return (check_other_esc_char(buf, hist, len, env));
}