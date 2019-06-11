/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:39:45 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/08 13:38:58 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	i = 0;
	s = (const unsigned char*)src;
	d = (unsigned char*)dest;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return ((void*)d + (i + 1));
		i++;
	}
	return (NULL);
}
