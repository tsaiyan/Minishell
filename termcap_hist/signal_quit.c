#include "header.h"

void	signal_quit(int sig)
{
	pid_t	pid;

	(void)sig;
	g_sig.sigquit = TRUE;
	pid = waitpid(-1, 0, WNOHANG);
	if (pid == 0)
	{
		write(1, "Quit: 3\n", 8);
		g_sig.exit_status = 131;
	}
}
