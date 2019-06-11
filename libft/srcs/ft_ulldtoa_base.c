/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulldtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:11:00 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/08 15:28:36 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ulldtoa_base_count(unsigned long long int nb, int base)
{
	int	i;

	i = 1;
	while (nb /= base)
		++i;
	return (i);
}

char		*ft_ulldtoa_base(unsigned long long int nb, int base)
{
	char	*ret;
	int		i;

	i = ulldtoa_base_count(nb, base);
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i--] = '\0';
	while (i > -1)
	{
		ret[i--] = (nb % base) + (nb % base > 9 ? 'a' - 10 : '0');
		nb /= base;
	}
	return (ret);
}
