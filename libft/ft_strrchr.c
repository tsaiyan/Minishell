/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:02:47 by egums             #+#    #+#             */
/*   Updated: 2020/10/30 20:45:48 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		flag;

	flag = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			tmp = (char *)s;
			flag = 1;
		}
		s++;
		if (!*s && flag == 1)
			return ((char *)tmp);
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)NULL);
}
