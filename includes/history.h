#ifndef HISTORY_H
# define HISTORY_H

void 		history_init(t_hist *hist, struct termios *term, t_pars *pa);
void 		term_off(t_hist *hist);

int 			add_history_from_line(char *line, t_hist *hist);

int uplvl_take_hist_from_file(t_pars *pa, t_hist *hist, char **apple);
char 			*do_absolute_exec_path(char **apple);


int left_arrow(char *buf, int len, t_hist *hist);
int right_arrow(char *buf, int len, t_hist *hist);

int 		down_arrow();
int 		up_arrow();

#endif
