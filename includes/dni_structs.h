#ifndef DNI_STRUCTS_H
# define DNI_STRUCTS_H

typedef struct	s_pars
{
	char		*s;
	char 		*command;
	char 		**envp;
	int 		quot_flag;
	int 		back_slash;
	int 		count;
	int 		tmp;
	int 		tmp_flag;
}	t_pars;

typedef struct	s_frs
{
	const char	*substr;
	char		*str;
	const char	*rep_str;
	int			*i;
	int 		*lim1;
	int 		*lim2;
	int 		tmp_i;
	int 		tmp_j;
}				t_fts;

// quot flag 1 - " | 2 - '|

#endif
