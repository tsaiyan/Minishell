#ifndef HISTORY_H
# define HISTORY_H

void 		history_init(t_hist *hist, struct termios *term, t_pars *pa);

int left_arrow(char *buf, int len);
int right_arrow(char *buf, int len);

int 		down_arrow();
int 		up_arrow();

#endif
