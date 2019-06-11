/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:38:49 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/17 16:39:17 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*pf_get_lenght(t_params *t_arg, const char *format, int *i)
{
	while (format[*i] == 'h' || format[*i] == 'l' || format[*i] == 'j'
			|| format[*i] == 'z')
	{
		if (format[*i] == 'h')
		{
			if (t_arg->lenght == 2)
				t_arg->lenght = 1;
			else
				t_arg->lenght = 2;
		}
		if (format[*i] == 'l')
		{
			if (t_arg->lenght == 4)
				t_arg->lenght = 3;
			else
				t_arg->lenght = 4;
		}
		if (format[*i] == 'j')
			t_arg->lenght = 5;
		if (format[*i] == 'z')
			t_arg->lenght = 6;
		++(*i);
	}
	return (t_arg);
}
