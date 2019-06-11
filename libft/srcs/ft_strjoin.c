/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:43:05 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/05 16:50:55 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str != NULL)
	{
		i = 0;
		j = 0;
		while (s1[i])
		{
			str[i] = s1[i];
			++i;
		}
		while (s2[j])
		{
			str[i + j] = s2[j];
			++j;
		}
		str[i + j] = '\0';
		return (str);
	}
	return (NULL);
}
