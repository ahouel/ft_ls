/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:20:27 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/09 14:03:29 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*start;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((tmp = ft_lstnew(lst->content, lst->content_size)) == NULL)
		return (NULL);
	tmp = f(tmp);
	start = tmp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if ((tmp->next = ft_lstnew(lst->content, lst->content_size)) == NULL)
			return (NULL);
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (start);
}
