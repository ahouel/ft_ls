/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:18:23 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/03 13:02:04 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)(s + n);
	while (n--)
	{
		if (*ptr == c)
			return ((void*)ptr);
		if (n)
			ptr--;
	}
	return (NULL);
}
