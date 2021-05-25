#ifndef HISTORY_H
# define HISTORY_H

void	history_init(t_hist *hist, struct termios *term, t_pars *pa);
void	term_off(t_hist *hist);

int		add_history_from_line(char *line, t_hist *hist);
int		add_history_line(t_hist *hist, char *buf);

int		uplvl_take_hist_from_file(t_pars *pa, t_hist *hist, char **apple);
char	*do_absolute_exec_path(char **apple);

int		read_filehistory(t_hist *hist);

int		left_arrow(char *buf, int len, t_hist *hist);
int		right_arrow(char *buf, int len, t_hist *hist);

int		down_arrow(t_hist *hist);
int		up_arrow(t_hist *hist, int len);

int		backspace_key(char *buf, int len, t_hist *hist);
int		del_key(t_hist *hist);

char	**ft_realloc_2massive(char ***mass, char *arg, int len);
int		check_len_left_right(char *line);
int		eof_char(t_hist *hist, char **env, t_bin *b);
int		ctrlc_char(t_hist *hist);

int		end_key(t_hist *hist);
int		home_key(t_hist *hist);
int		check_array_is_ascii(char *buf);

void	move_to_cours_toleft(int len);
int		ctrl_forward_slash(t_hist *hist);
int		check_specific_dollar(char **arg, t_pars *pa, int *i, char *str);
int		check_specific_dollar2(char **arg, int *i);
int		check_empty_history(t_hist *hist, char *buf);

void	signal_quit(int sig);
void	signal_exit(int sig);
char	**alloc_uplvl(char *name_arg, int current_lvl);

#endif
