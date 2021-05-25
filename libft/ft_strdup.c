/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:09:10 by egums             #+#    #+#             */
/*   Updated: 2020/11/01 16:56:13 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * ++len);
	if (!res)
		exit(errno);
	return ((char *)ft_memcpy(res, s1, len));
}
