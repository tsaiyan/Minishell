/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:57:09 by egums             #+#    #+#             */
/*   Updated: 2020/11/04 14:35:49 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ret(unsigned long answer, int minus)
{
	unsigned long	ul_max;

	ul_max = 4294967295;
	if (answer > ul_max && minus == -1)
		return (0);
	if (answer > ul_max && minus == 1)
		return (-1);
	if (minus == 1)
		return ((int)answer);
	return ((int)answer * minus);
}

int			ft_atoi(const char *nptr)
{
	int				index;
	int				minus;
	unsigned long	answer;

	index = 0;
	minus = 1;
	answer = 0;
	while (nptr[index] == '\r' || nptr[index] == '\v' || nptr[index] == ' ' ||
			nptr[index] == '\n' || nptr[index] == '\f' || nptr[index] == '\t')
		index++;
	if (nptr[index] == '-')
		minus = -1;
	if (nptr[index] == '+' || nptr[index] == '-')
		index++;
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		answer = answer * 10 + nptr[index] - '0';
		index++;
	}
	return (ret(answer, minus));
}
