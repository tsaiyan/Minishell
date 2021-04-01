/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:11:22 by tphung            #+#    #+#             */
/*   Updated: 2021/04/01 19:15:50 by tphung           ###   ########.fr       */
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

char		*path_join(char *path_str, char *name)
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
		errno = 0;
		printf(" CHILD: Это процесс-потомок!\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1PATH= %s\n", path_name);
		stat = execve(path_name, argv, envp);
		printf(" CHILD: Выход!\n ОШИБКА:\n %s\n", strerror(errno));
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

char	*filename_parser(char *filename, char **envp)
{
	int		i;
	char	**path_str;
	char	*str;
	char	delim;

	i = 0;
	delim = ':';
	if (ft_strchr("./", filename[0]))
		return (filename);
	while(ft_strncmp(envp[i++], "PATH=", 5))
		;
	str = envp[--i];
	path_str = ft_split(str + 5, &delim);
	//printf("%s\n", strerror(errno));
	i = check_exist(path_str, filename);
	//if (i < 0)
	//	printf("%s\n", strerror(errno));
	str = path_join(path_str[i], filename);
	//if (str == 0)
	//	printf("%s\n", strerror(errno));
	return (str);
}

int			launcher(t_main *arg)
{
	char	*str;

	str = filename_parser(*(arg->argv + 1), arg->envp);
	fork_execve(arg->argv + 1, arg->envp, str);
	printf("PARENT: Выход!\n");
	return (0);
}
