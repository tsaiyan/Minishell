#include "header.h"

static void			take_terminal_type(char **terminal)
{
	*terminal = getenv("TERM");
	if (NULL == *terminal)
		*terminal = getenv("TERM");
}

void 		history_init(t_hist *hist, struct termios *term, t_pars *pa)
{
	int 	ret;

	tcgetattr(0, term);
	take_terminal_type(&hist->terminal);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_lflag &= ~(ISIG);
	tcsetattr(0, TCSANOW, term);
	hist->term = term;
	if (!hist->terminal)
		ret = tgetent(0, "xterm-256color");
	else
		ret = tgetent(0, hist->terminal);
	if (-1 == ret)
	{
		ft_errors(TERM_ERRORS);
		exit(TERM_ERRORS);
	}
	hist->term_cols = tgetnum("co");
	hist->term_lines = tgetnum("li");
	printf("%d\n", hist->term_cols);
	printf("%d\n", hist->term_lines);
}

void 		term_off(t_hist *hist)
{
	int		ret;

	hist->term->c_lflag |= (ECHO);
	hist->term->c_lflag |= (ICANON);
	hist->term->c_lflag |= (ISIG);
	tcsetattr(0, TCSANOW, hist->term);
	if (!hist->terminal)
		ret = tgetent(0, "xterm-256color");
	else
		ret = tgetent(0, hist->terminal);
	if (-1 == ret)
	{
		ft_errors(TERM_ERRORS);
		exit(TERM_ERRORS);
	}
}