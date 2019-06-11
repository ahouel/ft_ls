/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:52:16 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/05 15:24:38 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	maxlen;

	maxlen = ft_strlen(s1);
	if (ft_strlen(s2) > maxlen)
		maxlen = ft_strlen(s2);
	return (ft_strncmp(s1, s2, maxlen));
}
