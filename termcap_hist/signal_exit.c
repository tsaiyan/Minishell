#include "header.h"

void signal_exit(int sig)
{
	pid_t pid;

	pid = waitpid(0, 0, WNOHANG);
	g_sig.sigint = TRUE;
	if (!pid)
	{
		write (1, "\n", 1);
		if (g_sig.sigint == TRUE)
			g_sig.exit_status = 130;
	}
}
