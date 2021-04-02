#ifndef PRE_PARSING_H
# define PRE_PARSING_H

int pre_pars_branching(char *envp[], t_pars *pa);
int 			check_char(char *cur_arg, t_pars *pa);
int				check_spaces_prep(char *cur_arg, t_pars *pa);

int check_chars_subst(char **arg, t_pars *pa, int *i)

#endif
