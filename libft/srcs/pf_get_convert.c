/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:39:30 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/17 16:40:00 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*pf_get_convert(t_params *t_arg, const char *format, int *i)
{
	if (format[*i])
	{
		t_arg->convert = format[*i];
		++(*i);
	}
	if (t_arg->convert == 'U' || t_arg->convert == 'O' || t_arg->convert == 'B')
	{
		if (t_arg->lenght == 4)
			t_arg->lenght = 3;
		else
			t_arg->lenght = 4;
		t_arg->convert += 32;
	}
	if (t_arg->convert == 'C' || t_arg->convert == 'S')
	{
		t_arg->lenght = 4;
		t_arg->convert += 32;
	}
	return (t_arg);
}
