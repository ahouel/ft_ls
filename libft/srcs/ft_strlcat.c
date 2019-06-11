/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:22:31 by ahouel            #+#    #+#             */
/*   Updated: 2016/11/30 17:49:24 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size < destlen + 1)
		return (srclen + size);
	else
	{
		dest = ft_strncat(dest, src, size - destlen - 1);
		return (destlen + srclen);
	}
}
