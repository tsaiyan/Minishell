#ifndef VALID_H
# define VALID_H

int	check_semicolon_and_syntax(char *line, t_pars *pa, int i, int ret);
int	valid_redirects(char *line, int *i);
int	check_semicolon_and_syntax2(char *line, t_pars *pa, int *i, int ret);

#endif
