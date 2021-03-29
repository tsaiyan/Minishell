/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:50:15 by egums             #+#    #+#             */
/*   Updated: 2020/10/30 12:53:46 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1;
	const unsigned char *p2;

	p1 = (const unsigned char*)s1;
	p2 = (const unsigned char*)s2;
	while (n-- != 0)
		if (*p1++ != *p2++)
			return (*--p1 - *--p2);
	return (0);
}
