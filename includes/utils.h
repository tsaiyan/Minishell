#ifndef UTILS_H
# define UTILS_H

int ft_errors(int code);
int write_error(int code, char *arg);

char *ft_realloc(char *arg, int count);

int 			check_envp(char *curr_arg, t_pars *pa);

#endif
