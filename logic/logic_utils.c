#include "header.h"

void ft_nputs(char *str)
{
	write(1, "\n", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
int ft_puts(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	return (0);
}

void ft_putstr(char *str)
{
	if(str)
		write(1, str, ft_strlen(str));
}
void puts_2d(char **argv)
{
	int i = 0;

	while (argv[i])
		ft_putstr(argv[i++]);
	write(1, "\n", 1);
}