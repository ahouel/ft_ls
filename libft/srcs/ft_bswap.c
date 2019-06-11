/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:38:14 by ahouel            #+#    #+#             */
/*   Updated: 2017/11/15 10:28:12 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bswap(void *bytes, size_t len)
{
	unsigned char	*byte;
	unsigned char	tmp;
	size_t			len2;

	len > 0 ? len-- : 0;
	len2 = 0;
	byte = (unsigned char*)bytes;
	while (len > len2)
	{
		tmp = byte[len2];
		byte[len2] = byte[len];
		byte[len] = tmp;
		len--;
		len2++;
	}
}
