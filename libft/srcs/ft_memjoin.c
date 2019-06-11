/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:42:20 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/21 18:26:54 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(const void *p1, size_t len1, const void *p2, size_t len2)
{
	unsigned char	*ret;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)p1;
	s2 = (unsigned char*)p2;
	if (!p1 || !p2)
		return (NULL);
	if (!(ret = ft_memalloc(len1 + len2)))
		return (NULL);
	while ((int)(--len2) > -1)
		ret[len1 + len2] = s2[len2];
	while ((int)(--len1) > -1)
		ret[len1] = s1[len1];
	return ((void*)ret);
}
