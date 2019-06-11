/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:37:23 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/17 17:11:42 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*pf_get_width(t_params *t_arg, const char *format, int *i,
		va_list ap)
{
	int	width;

	width = 0;
	t_arg->width = (unsigned int)ft_atoi(format + *i);
	while ((format[*i] > 47 && format[*i] < 58) ||
			format[*i] == '-' || format[*i] == '+')
		++(*i);
	while (format[*i] == '*')
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			t_arg->width = (unsigned int)ft_abs(width);
			t_arg->flags[4] = 1;
		}
		else
			t_arg->width = (unsigned int)width;
		++(*i);
	}
	if ((format[*i] > 47 && format[*i] < 58) ||
			format[*i] == '-' || format[*i] == '+')
		return (pf_get_width(t_arg, format, i, ap));
	return (t_arg);
}
