/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:27:58 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/17 15:00:38 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	i = 0;
	s = (const unsigned char*)src;
	d = (unsigned char*)dest;
	if (s < d)
		while ((int)(--n) > -1)
			d[n] = s[n];
	else
		while (i < n)
		{
			d[i] = s[i];
			++i;
		}
	return ((void*)d);
}
