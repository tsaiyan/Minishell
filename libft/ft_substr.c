/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:24:00 by egums             #+#    #+#             */
/*   Updated: 2020/11/05 17:47:44 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static char	*alloc_empty(int len)
{
	char			*ret;

	ret = malloc(len);
	if (NULL == ret)
		return (NULL);
	if (len == 1)
		*ret = '\0';
	return (ret);
}

static char	*solve(char const *s, unsigned start, size_t len)
{
	int				j;
	char			*result;
	char			*ret;
	int				sub_len;

	j = -1;
	while (s[++j])
		if (start == (unsigned int)j)
		{
			sub_len = ft_strlen(s + j);
			len = ((int)len <= sub_len) ? len : (size_t)sub_len;
			if (!(result = alloc_empty(len + 1)))
				return (NULL);
			ret = result;
			while (len--)
				*result++ = s[j++];
			*result = '\0';
			return (ret);
		}
	return (NULL);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	tmp_len;

	if (!s)
		return (NULL);
	tmp_len = ft_strlen(s);
	if (len == 0 || tmp_len < start)
		return (alloc_empty(1));
	else
		return (solve(s, start, len));
	return (NULL);
}
