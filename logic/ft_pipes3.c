#include "header.h"

//allocations pipes arrays

void	pipe_allocations(t_bin *bin)
{
	bin->p_commands = (char **)ft_calloc(sizeof(char *), (bin->p_count + 2));
	if (!bin->p_commands)
		exit(errno);
	bin->p_argvs = (char ***)ft_calloc(sizeof(char **), (bin->p_count + 1 + 1));
	if (!bin->p_argvs)
		exit(errno);
}

void	pipe_argv_allocation(t_bin *bin, int n, int c)
{
	while (bin->argv[n] && ft_strcmp(bin->argv[n], "|"))
		n++;
	bin->p_argvs[c] = ft_calloc(sizeof(char *), n + 1 + 1);
	if (!bin->p_argvs[c])
		exit(errno);
}

// parsing pipes

void	write_pipes(t_bin *bin)
{
	int	i;
	int	c;
	int	k;

	i = 0;
	c = 0;
	pipe_allocations(bin);
	while (bin->argv[i])
	{
		k = 0;
		if (!ft_strcmp(bin->argv[i], "|") && i++)
			continue ;
		if (!its_redirect(bin->argv[i]))
			bin->p_commands[c] = bin->argv[i];
		find_write_and_delete_redirect(bin, i, c);
		pipe_argv_allocation(bin, i, c);
		bin->p_argvs[c][k] = bin->argv[i];
		i++;
		while (bin->argv[i] && ft_strcmp(bin->argv[i], "|"))
			bin->p_argvs[c][++k] = bin->argv[i++];
		c++;
	}
}

void	free_pipes(t_bin *bin)
{
	int	i;

	i = 0;
	free(bin->p_commands);
	while (bin->p_argvs[i])
	{
		free(bin->p_argvs[i]);
		i++;
	}
	free(bin->p_argvs);
}

int	redirect_index(int index, int i, t_bin *bin)
{
	if (i == 0 && (bin->to > 0 || bin->from > 0))
		return (0);
	else if (i == 0)
		return (-1);
	return (index - ft_massive_len(bin->p_argvs[i]) - bin->del_pipes + 1);
}
