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

// quot flag 1 - " | 2 - '|

#endif
