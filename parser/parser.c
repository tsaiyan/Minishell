#include "header.h"

int 		parser(char **argv, char **envp)
{
	for (int j = 0; envp[j] != NULL; j++)
	{printf("%s\n", envp[j]);}
	printf("\n");
	for (int i = 0; argv[i] != NULL; i++)
	{printf("%s\n", argv[i]);}
	ft_free_massive(argv);
	return (0);
}