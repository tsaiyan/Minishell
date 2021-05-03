#ifndef BUILT_IN_H
# define BUILT_IN_H

typedef struct	s_bin
{
	char		**argv;
	char		**envp;
	char		**ar_export;
	int			n_flag;
	int			argc;
	t_mylst		*export;
	t_mylst		*envp_lst;
}				t_bin;

void		ft_puts(char *str);
void		ft_putstr(char *str);
void		ft_nputs(char *str);
t_mylst		*arr_to_dlist(char **str);
void		print_list(t_mylst *start, int flag);
void		ft_echo(t_bin *bin);
int			ft_pwd(t_bin *bin);
int			ft_env(t_bin *bin);
void		ft_export(t_bin *bin);
t_mylst		*find_head(t_mylst *lst);
t_mylst		*arr_to_dlist(char **str);
void		free_my_lst(t_mylst *lst);

// typydef struct	s_mylst
// {
// 	char			*str;
// 	struct s_mylst*next;
// 	struct s_mylst *prev;
// }				t_mylst;


#endif