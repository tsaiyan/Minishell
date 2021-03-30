/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:11:22 by tphung            #+#    #+#             */
/*   Updated: 2021/03/30 17:53:42 by tphung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int			check_exist(char **path, char *file)
{
	int				i;
	size_t			l_f;
	DIR				*papka;
	struct dirent	*example;

	i = 0;
	while(path[i])
	{
		papka = 0;
		if((papka = opendir(path[i])))
		{
			while ((example = readdir(papka)))
			{
				l_f = (size_t)ft_strlen(example->d_name);
				if (ft_strncmp(example->d_name, file, l_f) == 0)
				{
					printf("path = %s file = %s\n", path[i], example->d_name);
				}
			}
			closedir(papka);
		}
		i++;
	}
	return (0);
}

int			launcher(t_main *arg, char *file)
{
	int		i;
	char	**path_str;
	char	*str;
	char	delim;

	i = 0;
	delim = ':';
	while(ft_strncmp(arg->envp[i++], "PATH=", 5))
		;
	str = arg->envp[--i];
	path_str = ft_split(str + 5, &delim);
	i = 0;
	while(path_str[i])
	{
		printf("%s\n", path_str[i++]);
	}
	printf("%d\n", check_exist(path_str, file));

	return (0);
}
