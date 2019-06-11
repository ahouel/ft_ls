/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dispatch_convert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:34:30 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/22 19:36:08 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_dispatch_convert(va_list ap, t_params *t_arg)
{
	char	*buf;

	buf = NULL;
	if (t_arg->convert == 'd' || t_arg->convert == 'i' ||
			t_arg->convert == 'D' || t_arg->convert == 'o' ||
			t_arg->convert == 'u' || t_arg->convert == 'x' ||
			t_arg->convert == 'X' || t_arg->convert == 'b')
		return (pf_convert_nbr(ap, t_arg));
	else if (t_arg->convert == 'c')
		return (pf_convert_char(ap, t_arg));
	else if (t_arg->convert == 's' || t_arg->convert == 'p')
		return (pf_convert_ptr(ap, t_arg));
	else if (t_arg->convert == '%')
	{
		buf = ft_strdup("%");
		return (buf);
	}
	buf = ft_strdup(&(t_arg->convert));
	return (buf);
}
