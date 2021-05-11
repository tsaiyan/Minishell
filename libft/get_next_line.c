/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:59:41 by egums             #+#    #+#             */
/*   Updated: 2021/01/12 19:59:42 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	ft_strlen_n(const char *s, char flag)
{
	int			len;

	len = 0;
	if (s == NULL)
		return (len);
	if (flag == 0)
	{
		while (*s)
		{
			len++;
			s++;
		}
		return (len);
	}
	while (*s != 0 && *s != '\n')
	{
		len++;
		s++;
	}
	if (*s == 0 && flag == 2)
		return (-1);
	return (len);
}

int	free_and_null(char **tmp, int flag)
{
	if ((*tmp) != NULL)
	{
		free(*tmp);
		*tmp = NULL;
	}
	if (flag == -1)
		return (-1);
	return (0);
}

int	ft_save_remains(char **tmp)
{
	char		*rtn;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(*tmp))
		return (0);
	i = ft_strlen_n(*tmp, 1);
	if ((*tmp)[i] == 0)
	{
		free_and_null(tmp, 0);
		return (0);
	}
	rtn = malloc(sizeof(char) * ((ft_strlen_n(*tmp, 0) - i) + 1));
	if (!rtn)
		return (1);
	i++;
	while ((*tmp)[i])
		rtn[j++] = (*tmp)[i++];
	rtn[j] = '\0';
	free_and_null(tmp, 0);
	*tmp = rtn;
	return (0);
}

int	ft_take_line(char **tmp, char **line)
{
	char		*ret;
	int			len;

	len = ft_strlen_n(*tmp, 1);
	ret = malloc(len + 1);
	if (!ret)
		return (1);
	ret[len] = '\0';
	while (--len != -1)
		ret[len] = (*tmp)[len];
	*line = ret;
	return (ft_save_remains(tmp));
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	char		*tmp;
	static char	*save;
	int			len;

	len = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (!ft_strchr_gnl(save, '\n') && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
			return (free_and_null(&buf, -1));
		buf[len] = '\0';
		tmp = save;
		save = ft_strjoin_gnl(tmp, buf);
		free_and_null(&tmp, 0);
	}
	free_and_null(&buf, 0);
	if (ft_take_line(&save, line))
		return (-1);
	if (len == 0)
		return (0);
	return (1);
}
