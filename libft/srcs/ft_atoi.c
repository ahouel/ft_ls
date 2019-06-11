/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:07:00 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/05 15:38:18 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		r;
	int		signe;

	i = 0;
	r = 0;
	signe = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		++i;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] > 47 && str[i] < 58)
	{
		r = r * 10;
		r = r + (int)str[i] - 48;
		++i;
	}
	return (signe * r);
}
