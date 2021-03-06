#ifndef PRE_PARSING_H
# define PRE_PARSING_H

int		pre_pars_branching(t_pars *pa, t_hist *hist, int ret, int check);
int		check_char(char **cur_arg, t_pars *pa, int *i);
int		check_spaces_prep(char *cur_arg, t_pars *pa);

int		check_chars_subst(char **arg, t_pars *pa, int *i);
void	check_quotes_subst(char *arg, t_pars *pa, int *i);
char	*copy_new_prepars_str(char *arg);
char	*copy_new_prepars_str_without(char *arg);
char	*pars_argument_before_semicolon(char **line, int i);

char	**second_pre_pars(char *arg, t_pars *pa);
char	*pre_pars_subs(char *arg, t_pars *pa);

int		del_env_arg(char **arg, char *str, int *i, t_pars *pa);
char	*take_arg_from_env(char *str, t_pars *pa);

int		check_esc_char(char *buf, t_hist *hist, int len);
void	check_forward_redirect(char **cur_arg, t_pars *pa, int *i);

#endif
