#ifndef UTILS_H
# define UTILS_H

int ft_errors(int code);
int write_error(int code, char *arg);

char *ft_realloc(char *arg, int count);
// func like std realloc with copy

char *find_substr_instr_and_replace(const char *substr, char *str,
									const char *rep_str, int *i);
// replaces the first argument that matches the parameters
// all lines no freed
// if (int *)i == NULL => find first argument that matches the parameters
// 		**  substr - string to find = S
// 		**  str - line in which need to find == STR
// 		**  rep_str - the string to be replaced with = 123
// 		=> 123TR
// if (int *)i != NULL => mov i to '3' index -> (123TR)

int check_envp(char **curr_arg, t_pars *pa, int *i, int stage);

#endif
