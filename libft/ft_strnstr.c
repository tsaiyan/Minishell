/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:07:30 by egums             #+#    #+#             */
/*   Updated: 2020/11/01 17:05:43 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		j;
	size_t		needle_len;

	j = 0;
	if (0 == (needle_len = ft_strlen(needle)))
		return ((char *)haystack);
	if (needle_len > ft_strlen(haystack) || len == 0 || needle_len > len)
		return (NULL);
	while ((len - needle_len) >= j && *needle)
	{
		if ((*needle == *haystack) &&
				(0 == ft_strncmp(haystack, needle, needle_len)))
			return ((char *)haystack);
		haystack++;
		j++;
	}
	return (NULL);
}
