#ifndef BUILT_IN_H
# define BUILT_IN_H

#include "limits.h"
typedef struct	s_bin
{
	char		**argv;
	char		**envp;
	char		**ar_export;
	int			n_flag;
	int			argc;
	t_mylst		*export;
	t_mylst		*envp_lst;
	char		**p_commands;
	char		***p_argvs;
	int			p_count;
	pid_t		pid;
	short		error;
	int			exit_status;
	short		exit_off;

	int 		from;
	int			to;
	int			append;
	int			indx_from;
	int			indx_to;
	int			savefd1;
	int			savefd0;
	int			del_pipes;
}				t_bin;

void		ft_puts(char *str);
void		ft_putstr(char *str);
void		ft_nputs(char *str);
t_mylst		*arr_to_dlist(char **str);
void		print_list(t_mylst *start, int flag);
void		ft_echo(t_bin *bin, char **argv);
int			ft_pwd(t_bin *bin);
int			ft_env(t_bin *bin);
void		ft_export(t_bin *bin, char **argv);
t_mylst		*find_head(t_mylst *lst);
t_mylst		*arr_to_dlist(char **str);
int			free_my_lst(t_mylst *lst);
char		*ft_strdup_chr(char *str, char end);
t_mylst		*my_lst_last(t_mylst *current);
t_mylst		*find_head(t_mylst *lst);
void		sort_list(t_bin *bin);
int			my_lst_size(t_mylst *lst);
void		ft_cd(t_bin *bin, char **argv);
void		ft_exit(char **argv);
void		ft_unset(t_bin *bin, char **argv);
char		*ft_get_value(t_mylst *lst, char *key);
void		list_to_envp(t_bin *bin);
t_mylst		*find_lst(t_mylst *lst, char *key);
int			command_error(char *command, int flag);
int			ft_pipes(t_bin *bin);
int			check_pipes(t_bin *bin);
void		ft_execve(t_bin *bin, char *command, char **argv);
char		*get_excve_str(t_bin *bin, char *command, char **argv);
void		ft_execve(t_bin *bin, char *execve_str, char **argv);
void		ft_redirects(t_bin *bin, char **argv);
int			find_redirects(t_bin * bin);
int			ft_redopen(t_bin *bin, char *way, int flag, int index);
void		ft_close_redifd(t_bin * bin);


void		launch_minishell(void);
#endif