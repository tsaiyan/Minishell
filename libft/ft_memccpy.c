/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:08:17 by egums             #+#    #+#             */
/*   Updated: 2020/11/01 17:07:32 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
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
			if (s[j] == (unsigned char)c)
				return ((void*)dst + (++j));
			j++;
		}
	}
	return (NULL);
}
