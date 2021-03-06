#ifndef UTILS_H
# define UTILS_H

int			ft_errors(int code);
// print minishell: strerror(errno);
int			write_error(int code, char *arg);

char		*ft_realloc(char *arg, int count);
// func like std realloc with copy

char		*find_substr_in_str_and_replace(char *substr, char *str, \
char *rep_str, int *i);
// replaces the first argument that matches the parameters
// all lines no freed
// if (int *)i == NULL => find first argument that matches the parameters
// 		**  substr - string to find = S
// 		**  str - line in which need to find == STR
// 		**  rep_str - the string to be replaced with = 123
// 			=> 123TR
// move i to begin changes
// need all time do pointer in int (&i) can be (int)0
// WARNING! - i == (int*)!!!

int			check_envp(char **curr_arg, t_pars *pa, int *i, int stage);

int			pass_strlen(char *str);
// pass EMPTY DEFINES and check_semicolon len not considering them

char		**copy_env_massive(char **env);
// copy envairement massive

void		ft_free_massive(char **mass);
//realloc this func from utils to libft

int			ft_putchar(int c);

char		**ft_del_index_in2massive(char **old, int index);
// return new 2d massive char(*) without current index
//
// old = char **old {"1", "2", NULL}
//
// ft_del...(old, 1) => new = char **new {"1", NULL}
//
//

void		trim_space_in_begin(char **str, int i, int j, int len);
int			ft_strlen_n(const char *s, char flag);

#endif
