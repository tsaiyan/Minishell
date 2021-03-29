/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:45:46 by egums             #+#    #+#             */
/*   Updated: 2020/11/04 14:55:16 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*ret;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(ret = malloc(len + 1)))
		return (NULL);
	len = 0;
	while (s[len])
	{
		ret[len] = f(len, s[len]);
		len++;
	}
	ret[len] = '\0';
	return (ret);
}
