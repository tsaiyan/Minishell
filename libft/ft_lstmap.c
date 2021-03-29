/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:30:18 by egums             #+#    #+#             */
/*   Updated: 2020/11/05 19:46:47 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list		*tmp_begin;
	t_list		*new;
	t_list		*begin_lst;

	if (!f || !lst)
		return (NULL);
	tmp_begin = lst;
	begin_lst = NULL;
	while (tmp_begin)
	{
		if (!(new = ft_lstnew(f(tmp_begin->content))))
		{
			ft_lstclear(&begin_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&begin_lst, new);
		tmp_begin = tmp_begin->next;
	}
	return (begin_lst);
}
