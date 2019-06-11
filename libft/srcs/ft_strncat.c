/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:31:11 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/02 15:46:07 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	destlen;

	destlen = ft_strlen(dest);
	i = 0;
	while (src[i] && i < n)
	{
		dest[destlen + i] = src[i];
		++i;
	}
	dest[destlen + i] = '\0';
	return (dest);
}
