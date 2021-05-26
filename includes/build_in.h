#ifndef BUILD_IN_H
# define BUILD_IN_H

# include "limits.h"
# include "dirent.h"
# include "libft.h"
# include <unistd.h>
# define MAX_ARGV 1000

typedef struct s_mylst
{
	char			*value;
	char			*key;
	int				equal;
	int				add;
	int				plus;
	int				dollar;
	struct s_mylst	*next;
	struct s_mylst	*prev;
}	t_mylst;

typedef struct s_bin
{
	char			**argv;
	char			**envp;
	char			**ar_export;
	int				n_flag;
	int				argc;
	t_mylst			*export;
	t_mylst			*envp_lst;
	char			**p_commands;
	char			***p_argvs;
	int				p_count;
	pid_t			pid;
	short			error;
	int				exit_status;
	short			exit_off;
	int				ret;
	int				from;
	int				to;
	int				append;
	int				indx_from;
	int				indx_to;
	int				savefd1;
	int				savefd0;
	int				del_pipes;

	char			*temp_old_dir;
	char			*home_path;
	char			dir[PATH_MAX];

	int				fds_red[MAX_ARGV][2];
	int				fd_pipes[MAX_ARGV][2];
	int				fds_to_close[MAX_ARGV];
	char			*test_str;
	int				error_ret;

	DIR				*folder;
	struct dirent	*dirent;
	char			*execve_str;
	char			*dir_to_open;
	char			**split_str;
	char			*path;
	char			*com_to_ins;
	char			*red_to_ins;
	char			*file_to_ins;
}					t_bin;

int			ft_puts(char *str);
void		ft_putstr(char *str);
void		ft_nputs(char *str);
void		print_list(t_mylst *start, int flag);
int			ft_echo(t_bin *bin, char **argv);
int			ft_pwd(void);
int			ft_env(t_bin *bin);
void		ft_export(t_bin *bin, char **argv);
int			free_my_lst(t_mylst *lst);
char		*ft_strdup_chr(char *str, char end);
void		sort_list(t_bin *bin);
int			my_lst_size(t_mylst *lst);
int			ft_cd(t_bin *bin, char **argv);
int			ft_exit(char **argv);
void		ft_unset(t_bin *bin, char **argv);
char		*ft_get_value(t_mylst *lst, char *key);
void		list_to_envp(t_bin *bin);
int			command_error(char *command, int flag);
void		ft_pipes(t_bin *bin);
int			check_pipes(t_bin *bin);
void		ft_execve(t_bin *bin, char *execve_str, char **argv, int status);
char		*get_excve_str(t_bin *bin, char *command, char **argv);
void		ft_redirects(t_bin *bin, char **argv);
int			find_redirects(t_bin *bin);
int			ft_redopen(t_bin *bin, char *way, int flag, int index);
void		ft_close_redifd(t_bin *bin);
int			change_oldpwd(t_bin *bin, char *str);
int			cd_with_minus(t_bin *bin, char **argv);
int			cd_outputs(char **argv, int flag);
void		launch_minishell(void);
int			check_ret(t_bin *bin, int ret, char *way);
int			its_redirect(char *str);
int			add_fd_to_close(t_bin *bin, int fd, int ret);
void		pipe_argv_allocation(t_bin *bin, int n, int c);
void		write_pipes(t_bin *bin);
void		free_pipes(t_bin *bin);
int			redirect_index(int index, int i, t_bin *bin);
int			check_pipes(t_bin *bin);
int			ft_write_red_fd_in_pipes(t_bin *bin, char *command, int i, int c);
int			find_write_and_delete_redirect(t_bin *bin, int i, int c);
t_mylst		*arr_to_dlist(char **str);
t_mylst		*my_lst_last(t_mylst *current);
t_mylst		*find_head(t_mylst *lst);
t_mylst		*find_lst(t_mylst *lst, char *key);
t_mylst		*my_lst_add_back(t_mylst *start, t_mylst *add);
t_mylst		*my_lst_new(char *str);
int			already_exist_key(t_mylst *current, t_mylst *add);
void		print_list(t_mylst *start, int flag);
int			validate_export(char *str);
void		sort_list(t_bin *bin);
void		swap_list(t_mylst *start, t_mylst *next);
int			it_not_builtin(char *command);
void		free_already_exist_key(t_mylst *add, t_mylst *current, char *cur);
char		*ret_get_excve_str(t_bin *bin);
int			make_path_str(t_bin *bin, char *command);
void		free_and_write_get_execve_str(t_bin *bin, int i);
void		ft_free_massive(char **mass);
void		free_diropen(t_bin *bin);
void		excve_exit_errno(char *execve_str);
void		make_redirects(t_bin *bin);
void		make_redirects(t_bin *bin);
void		ft_check_malloc(char *str);
int			type_of_redirect(char *str, int i);
#endif