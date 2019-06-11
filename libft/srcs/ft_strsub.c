/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:47:35 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/12 17:55:31 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		ret[i] = s[start];
		++i;
		++start;
	}
	ret[i] = '\0';
	return (ret);
}
