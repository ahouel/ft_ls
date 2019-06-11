/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:38:11 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/17 17:10:58 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*pf_get_precision(t_params *t_arg, const char *format, int *i,
		va_list ap)
{
	int	precision;

	precision = 0;
	if (format[*i] == '.')
	{
		++(*i);
		t_arg->precision = ft_atoi(format + *i);
		while ((format[*i] > 47 && format[*i] < 58) || format[*i] == '*' ||
				format[*i] == '-' || format[*i] == '+')
		{
			if (format[*i] == '*')
				t_arg->precision = va_arg(ap, int);
			++(*i);
		}
	}
	return (t_arg);
}
