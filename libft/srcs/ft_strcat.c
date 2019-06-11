/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:19:13 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/17 14:11:28 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	destlen;

	destlen = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[destlen + i] = src[i];
		++i;
	}
	dest[destlen + i] = '\0';
	return (dest);
}
