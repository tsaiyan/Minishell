/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:11:22 by tphung            #+#    #+#             */
/*   Updated: 2021/03/31 15:45:41 by tphung           ###   ########.fr       */
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
					closedir(papka);
					return (i);
				}
			}
			closedir(papka);
		}
		i++;
	}
	return (-1);
}

char		*path_exec(char *path_str, char *name)
{
	char	*tmp;
	char	*path_name;

	tmp = ft_strjoin(path_str, "/");
	if (!tmp)
		return (0);
	path_name = ft_strjoin(tmp, name);
	if (!path_name)
		return (0);
	return (path_name);
}

int			fork_execve(char **argv, char **envp, char *path_name)
{
	int		stat;
	pid_t	pid;

	pid = fork();
	stat = 123;
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		printf(" CHILD: Это процесс-потомок!\n");
		stat = execve(path_name, argv, envp);
		printf(" CHILD: Выход!\n");
		exit(stat);
	}
	else
	{
		wait(&stat);
		printf("PARENT: Это процесс-родитель!\n");
		printf("stat = %d\n", stat);
	}
	return (0);
}

int			launcher(t_main *arg)
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
	if ((i = check_exist(path_str, *(arg->argv + 1))) < 0)
		return (-1);
	if ((str = path_exec(path_str[i], *(arg->argv + 1))) == 0)
		return (-1);
	fork_execve(arg->argv + 1, arg->envp, str);
	printf("PARENT: Выход!\n");
	return (0);
}
