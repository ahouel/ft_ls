/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:42:39 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/08 15:22:33 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*cpy;

	i = 0;
	while (s[i] && i < n)
		++i;
	if (!(cpy = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		cpy[i] = s[i];
		++i;
	}
	cpy[i] = '\0';
	return (cpy);
}
