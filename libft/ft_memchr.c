/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:08:22 by egums             #+#    #+#             */
/*   Updated: 2020/11/01 16:58:07 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p;

	p = (const unsigned char *)s;
	while (n-- != 0)
		if (*p++ == (unsigned char)c)
			return ((void *)(p - 1));
	return (NULL);
}
