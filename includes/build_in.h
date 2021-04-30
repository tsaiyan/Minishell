#ifndef BUILT_IN_H
# define BUILT_IN_H

void ft_puts(char *str);
void ft_putstr(char *str);
void ft_nputs(char *str);

// typydef struct	s_mylst
// {
// 	char			*str;
// 	struct s_mylst*next;
// 	struct s_mylst *prev;
// }				t_mylst;

typedef struct	s_bin
{
	char		**argv;
	char		**envp;
	char		**ar_export;
	int			n_flag;
	int			argc;
	t_list		*export;
}				t_bin;

#endif