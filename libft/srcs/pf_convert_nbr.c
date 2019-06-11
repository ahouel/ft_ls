/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:44:22 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/22 19:25:23 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*pf_apply_nb(long long int nb, t_params *t_arg)
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

static char	*pf_apply_nbp(unsigned long long int nbp, t_params *t_arg)
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

static char	*convert_di(va_list ap, t_params *t_arg)
{
	char			*buf;
	long long int	nb;

	nb = 0;
	buf = NULL;
	if (t_arg->lenght == 0)
		nb = va_arg(ap, int);
	else if (t_arg->lenght == 1)
		nb = (signed char)va_arg(ap, int);
	else if (t_arg->lenght == 2)
		nb = (short int)va_arg(ap, int);
	else if (t_arg->lenght == 4)
		nb = va_arg(ap, long int);
	else if (t_arg->lenght == 3)
		nb = va_arg(ap, long long int);
	else if (t_arg->lenght == 5)
		nb = va_arg(ap, intmax_t);
	else if (t_arg->lenght == 6)
		nb = va_arg(ap, ssize_t);
	buf = pf_apply_nb(nb, t_arg);
	return (buf);
}

static char	*convert_ouxb(va_list ap, t_params *t_arg)
{
	char					*buf;
	unsigned long long int	nbp;

	nbp = 0;
	buf = NULL;
	if (t_arg->lenght == 0)
		nbp = va_arg(ap, unsigned int);
	else if (t_arg->lenght == 1)
		nbp = (unsigned char)va_arg(ap, unsigned int);
	else if (t_arg->lenght == 2)
		nbp = (unsigned short int)va_arg(ap, unsigned int);
	else if (t_arg->lenght == 4)
		nbp = va_arg(ap, unsigned long int);
	else if (t_arg->lenght == 3)
		nbp = va_arg(ap, unsigned long long int);
	else if (t_arg->lenght == 5)
		nbp = va_arg(ap, uintmax_t);
	else if (t_arg->lenght == 6)
		nbp = va_arg(ap, size_t);
	buf = pf_apply_nbp(nbp, t_arg);
	return (buf);
}

char		*pf_convert_nbr(va_list ap, t_params *t_arg)
{
	char					*buf;
	long long int			nb;

	buf = NULL;
	nb = 0;
	if (t_arg->convert == 'D')
	{
		if (t_arg->lenght == 4)
			nb = va_arg(ap, long int);
		else if (t_arg->lenght == 5)
			nb = va_arg(ap, intmax_t);
		else if (t_arg->lenght == 6)
			nb = va_arg(ap, ssize_t);
		else
			nb = va_arg(ap, intmax_t);
		buf = pf_apply_nb(nb, t_arg);
	}
	if (t_arg->convert == 'd' || t_arg->convert == 'i')
		buf = convert_di(ap, t_arg);
	else if (t_arg->convert == 'o' || t_arg->convert == 'u' ||
			t_arg->convert == 'x' || t_arg->convert == 'X' ||
			t_arg->convert == 'b')
		buf = convert_ouxb(ap, t_arg);
	return (buf);
}
