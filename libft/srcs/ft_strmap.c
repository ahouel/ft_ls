/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:57:25 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/08 13:47:46 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			str[i] = f((char)s[i]);
			++i;
		}
	return (str);
}
