/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:17:39 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/05 16:14:20 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	i = 0;
	if (str != NULL)
		while (s[i])
		{
			str[i] = f(i, (char)s[i]);
			++i;
		}
	return (str);
}
