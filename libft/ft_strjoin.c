/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:57:36 by egums             #+#    #+#             */
/*   Updated: 2020/11/04 14:38:51 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int			sum_len;
	char		*ret;
	char		*dst;

	if (NULL == s1)
		return (ft_strdup(s2));
	sum_len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (sum_len + 1));
	if (NULL == ret)
		return (NULL);
	dst = ret;
	while (*s1)
		*dst++ = *s1++;
	*dst++ = '\0';
	ft_strlcat(ret, s2, sum_len + 1);
	return (ret);
}
