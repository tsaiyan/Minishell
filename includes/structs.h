#ifndef STRUCTS_H
# define STRUCTS_H

# include "dni_structs.h"

typedef struct	s_main
{
	int			count;
	int			pipe_in;
	int			pipe_out;
	int			red_in;
	int 		red_out;
	char		*red_name;
	int			fd_read;
	int 		fd_write;
	int			save_fd_read;
	int			save_fd_write;
	int 		argc;
	char 		**argv;
	char		**envp;
}	t_main;

#endif
