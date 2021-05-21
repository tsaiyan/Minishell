#include "header.h"

void signal_exit(int sig)
{
	pid_t pid;

	pid = waitpid(0, 0, WNOHANG);
	g_sig.sigint = TRUE;
	if (!pid)
	{
		kill(pid, sig);
		if (g_sig.sigint == TRUE)
		g_sig.exit_status = 130;
	}
}
