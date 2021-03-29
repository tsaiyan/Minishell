/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:01:10 by egums             #+#    #+#             */
/*   Updated: 2020/11/01 17:07:55 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*tmpdst;
	const char	*tmpsrc;
	size_t		tmp;
	size_t		dlen;

	tmpdst = dst;
	tmpsrc = src;
	tmp = dstsize;
	while (*dst != '\0' && tmp-- != 0)
		dst++;
	dlen = dst - tmpdst;
	tmp = dstsize - dlen;
	if (tmp-- == 0)
		return (dlen + ft_strlen(tmpsrc));
	while (*src != '\0' && tmp-- != 0)
		*dst++ = *src++;
	while (*src != '\0')
		src++;
	*dst = '\0';
	return (dlen + (src - tmpsrc));
}
