/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:23:14 by egums             #+#    #+#             */
/*   Updated: 2020/11/06 19:00:34 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_arg(char arg, char *term)
{
	while (*term)
	{
		if (arg == *term)
			return (1);
		term++;
	}
	return (0);
}

static char		*word_alloc(const char *str, char *c)
{
	char		*ret_word;
	int			index;

	index = 0;
	while (!(check_arg(str[index], c)) && str[index])
		index++;
	if (!(ret_word = (char *)malloc(index + 1)))
		return (NULL);
	index = -1;
	while (!(check_arg(str[++index], c)) && str[index])
		ret_word[index] = str[index];
	ret_word[index] = '\0';
	return (ret_word);
}

static int		count_word(const char *str, char *c)
{
	int			count;

	count = 0;
	while (*str)
	{
		if (*str && !(0 == !(check_arg(*str, c))))
		{
			count++;
			while (*str && !(0 == !(check_arg(*str, c))))
				str++;
		}
		while (*str && check_arg(*str, c))
			str++;
	}
	return (count);
}

void			ft_free(char **ret)
{
	char		**begin;

	begin = ret;
	while (*ret != NULL)
	{
		free(*ret);
		*ret = NULL;
		ret++;
	}
	ret = begin;
	free(ret);
	begin = NULL;
	ret = NULL;
}

char			**ft_split(char const *s, char *c)
{
	char		**ret;
	int			index;

	index = 0;
	if (!s || !(ret = (char **)malloc((count_word(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (*s)
	{
		while (*s && check_arg(*s, c))
			s++;
		if (*s && !(check_arg(*s, c)))
		{
			if (!(ret[index] = word_alloc(s, c)))
			{
				ft_free(ret);
				return (NULL);
			}
			index++;
			while (*s && !(check_arg(*s, c)))
				s++;
		}
	}
	ret[index] = NULL;
	return (ret);
}
