/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:08:56 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/09 18:17:07 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(const char *str, size_t len)
{
	char	*new;

	if (str == NULL)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(str) + len)))
		return (NULL);
	new = ft_strcat(new, str);
	return (new);
}
