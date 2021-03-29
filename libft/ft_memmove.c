/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:47:30 by egums             #+#    #+#             */
/*   Updated: 2020/11/01 17:00:31 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (len != 0 && dst != src)
	{
		if (d >= (s + len) || d <= s)
			while (len--)
				*d++ = *s++;
		else
		{
			s = s + (len - 1);
			d = d + (len - 1);
			while (len--)
				*d-- = *s--;
		}
	}
	return (dst);
}
