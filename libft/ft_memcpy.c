/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:39:16 by egums             #+#    #+#             */
/*   Updated: 2020/11/01 17:06:42 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
