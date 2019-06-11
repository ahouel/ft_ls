/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldtoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 09:17:22 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/13 16:26:57 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	lldtoa_base_count(long long int nb, int base, int *neg)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		*neg = -1;
		++i;
	}
	while (nb /= base)
		++i;
	return (i);
}

char		*ft_lldtoa_base(long long int nb, int base)
{
	char					*ret;
	int						i;
	int						neg;
	unsigned long long int	r;

	neg = 1;
	i = lldtoa_base_count(nb, base, &neg);
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i--] = '\0';
	r = (unsigned long long int)(nb * neg);
	while (i > -1)
	{
		ret[i] = (r % base) + (r % base > 9 ? 'a' - 10 : '0');
		r /= base;
		i--;
	}
	if (neg == -1)
		ret[0] = '-';
	return (ret);
}
