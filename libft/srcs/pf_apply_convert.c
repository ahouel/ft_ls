/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:26:42 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/22 17:19:30 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_apply_nb(long long int nb, t_params *t_arg)
{
	if (t_arg->convert == 'D')
	{
		if (t_arg->lenght == 0)
			nb = (unsigned long long int)nb;
	}
	if (nb < 0)
		t_arg->neg = 1;
	return (ft_lldtoa_base(nb, 10));
}

char	*pf_apply_nbp(unsigned long long int nbp, t_params *t_arg)
{
	char	*buf;
	int		i;

	i = -1;
	buf = NULL;
	if (t_arg->convert == 'x')
		return (ft_ulldtoa_base(nbp, 16));
	else if (t_arg->convert == 'X')
	{
		buf = ft_ulldtoa_base(nbp, 16);
		while (buf[++i])
			if (buf[i] > 96 && buf[i] < 123)
				buf[i] -= 32;
		return (buf);
	}
	else if (t_arg->convert == 'o')
		return (ft_ulldtoa_base(nbp, 8));
	else if (t_arg->convert == 'b')
		return (ft_ulldtoa_base(nbp, 2));
	else
		return (ft_ulldtoa_base(nbp, 10));
}
