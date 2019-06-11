/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:35:04 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/05 15:19:05 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	littlelen;

	i = 0;
	littlelen = ft_strlen(little);
	if (littlelen == 0)
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && i + j < len)
			++j;
		if (j == littlelen)
			return ((char*)big + i);
		++i;
	}
	return (NULL);
}
