/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:17:45 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/08 14:56:48 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*cpy;

	i = 0;
	while (s[i])
		++i;
	if (!(cpy = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		++i;
	}
	cpy[i] = '\0';
	return (cpy);
}
