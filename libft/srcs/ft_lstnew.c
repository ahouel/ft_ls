/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:26:10 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/10 11:24:22 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;

	if (!(lstnew = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		lstnew->content_size = 0;
		lstnew->content = NULL;
	}
	else
	{
		if (!(lstnew->content = malloc(content_size)))
		{
			free(lstnew);
			return (NULL);
		}
		lstnew->content = ft_memcpy(lstnew->content, content, content_size);
		lstnew->content_size = content_size;
	}
	lstnew->next = NULL;
	return (lstnew);
}
