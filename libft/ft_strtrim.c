/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:31:37 by egums             #+#    #+#             */
/*   Updated: 2020/11/04 14:39:38 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char			*ft_strtrim(char const *s1, char const *set)
{
	int			found_index;
	char		*ret;

	if (!set || !s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (!(found_index = ft_strlen(s1)))
		return (ft_strdup(""));
	while (found_index && ft_strchr(set, s1[found_index]))
		found_index--;
	ret = ft_substr((char*)s1, 0, found_index + 1);
	return (ret);
}
