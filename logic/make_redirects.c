#include "header.h"

int	ft_strlcpy2(char *dest, const char *src, int start, int end)
{
	int	i;
	int	n;

	i = start;
	n = 0;
	if (!dest && !src)
		return (0);
	if (!end)
		end = ft_strlen(src);
	while (src[i] && n < end)
	{
		dest[n] = src[i];
		i++;
		n++;
	}
	dest[n] = '\0';
	return (n);
}

void	make_new_str(t_bin *bin, int i, int j)
{
	int	red_len;

	red_len = type_of_redirect(bin->argv[i], j);
	bin->com_to_ins = ft_calloc(sizeof(char *), j + 1);
	ft_check_malloc(bin->com_to_ins);
	bin->file_to_ins = ft_calloc(sizeof(char *), \
	ft_strlen(bin->argv[i] - j) + 1);
	ft_check_malloc(bin->file_to_ins);
	bin->red_to_ins = ft_calloc(sizeof(char *), 4);
	ft_check_malloc(bin->red_to_ins);
	ft_strlcpy2(bin->com_to_ins, bin->argv[i], 0, j);
	ft_strlcpy2(bin->file_to_ins, bin->argv[i], j + red_len, 0);
	ft_strlcpy2(bin->red_to_ins, bin->argv[i], j, red_len);
}

int	insert_thee_arrays(t_bin *bin, int change)
{
	char	**new_argv;
	int		i;
	int		j;

	j = 0;
	i = -1;
	new_argv = ft_calloc(sizeof(char **), ft_massive_len(bin->argv) + 5);
	while (++i != change)
	{
		new_argv[i] = bin->argv[j];
		j++;
	}
	new_argv[i++] = bin->com_to_ins;
	new_argv[i++] = bin->red_to_ins;
	new_argv[i++] = bin->file_to_ins;
	while (bin->argv[++j])
	{
		new_argv[i] = bin->argv[j];
		i++;
	}
	free(bin->argv[change]);
	free(bin->argv);
	bin->argv = new_argv;
	return (1);
}

int	it_not_redirect_str(char *str)
{
	if (!ft_strcmp(str, "\007"))
		return (0);
	if (!ft_strcmp(str, "\007\007"))
		return (0);
	if (!ft_strcmp(str, "\006"))
		return (0);
	return (1);
}

void	make_redirects(t_bin *bin)
{
	int	i;
	int	j;
	int	flag;

	flag = 1;
	while (flag)
	{
		i = -1;
		flag = 0;
		while (bin->argv[++i] && flag == 0)
		{
			if (!it_not_redirect_str(bin->argv[i]))
				continue ;
			j = -1;
			while (bin->argv[i][++j] && flag == 0)
			{
				if (bin->argv[i][j] == FRWRD_RDRCT || bin->argv[i][j] == RVRS_RDRCT)
				{
					make_new_str(bin, i, j);
					flag = insert_thee_arrays(bin, i);
					break ;
				}
			}
		}
	}
}
