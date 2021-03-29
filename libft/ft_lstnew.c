/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:08:41 by egums             #+#    #+#             */
/*   Updated: 2020/11/04 19:19:00 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *result;

	result = (t_list*)malloc(sizeof(t_list));
	if (NULL == result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
