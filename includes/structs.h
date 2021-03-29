#ifndef STRUCTS_H
# define STRUCTS_H

# include "dni_structs.h"

typedef struct	s_main
{
	int			pipe_flag;
	int 		red_flag;
	int			fd_in;
	int 		fd_out;
	int 		argc;
	char 		**argv;
	char		**envp;
}	t_main;

#endif
