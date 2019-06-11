/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:16:24 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/10 11:23:42 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		ft_putstr((char const*)(lst->content));
		ft_putnbr((int)(lst->content_size));
		lst = lst->next;
		++count;
	}
	ft_putstr("Nombre de structure : ");
	ft_putnbr(count);
}
