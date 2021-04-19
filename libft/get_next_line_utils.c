/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:59:56 by egums             #+#    #+#             */
/*   Updated: 2021/01/12 20:00:09 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void				*ft_memcpy_gnl(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			j;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	j = 0;
	if (n != 0 && dst != src)
	{
		while (j < n)
		{
			d[j] = s[j];
			j++;
		}
	}
	return (dst);
}

char				*ft_strdup_gnl(const char *s1)
{
	size_t			len;
	char			*res;

	len = ft_strlen_n(s1, 0);
	res = (char *)malloc(sizeof(char) * ++len);
	if (NULL == res)
		return (NULL);
	return ((char *)ft_memcpy_gnl(res, s1, len));
}

int					ft_strlcat_gnl(char *dst, const char *src, int dstsize)
{
	const char		*tmpdst;
	const char		*tmpsrc;
	unsigned long	tmp;
	unsigned long	dlen;

	tmpdst = dst;
	tmpsrc = src;
	tmp = dstsize;
	while (*dst != '\0' && tmp-- != 0)
		dst++;
	dlen = dst - tmpdst;
	tmp = dstsize - dlen;
	if (tmp-- == 0)
		return (dlen + ft_strlen_n(tmpsrc, 0));
	while (*src != '\0' && tmp-- != 0)
		*dst++ = *src++;
	while (*src != '\0')
		src++;
	*dst = '\0';
	return (dlen + (src - tmpsrc));
}

char				*ft_strjoin_gnl(char *s1, char *s2)
{
	int				sum_len;
	char			*ret;
	char			*dst;

	if (NULL == s1)
		return (ft_strdup_gnl(s2));
	sum_len = ft_strlen_n(s1, 0) + ft_strlen_n(s2, 0);
	if (!(ret = malloc(sizeof(char) * (sum_len + 1))))
		return (NULL);
	dst = ret;
	while (*s1)
		*dst++ = *s1++;
	*dst++ = '\0';
	ft_strlcat_gnl(ret, s2, sum_len + 1);
	return (ret);
}

int					ft_strchr_gnl(const char *s, int c)
{
	int				index;

	index = 0;
	if (NULL == s)
		return (0);
	while (s[index] != 0)
	{
		if (s[index] == c)
			return (1);
		index++;
	}
	return (0);
}
