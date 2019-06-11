/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:45:07 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/27 17:11:54 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_wchar(va_list ap)
{
	char			*buf;
	int				c;
	wint_t			wc;

	buf = NULL;
	if (MB_CUR_MAX < 4)
	{
		c = va_arg(ap, int);
		if (c < 0 || c > 255)
			return (ft_strdup("no"));
		buf = ft_strnew(1);
		*buf = (unsigned char)c;
	}
	else
	{
		wc = va_arg(ap, wint_t);
		buf = (char*)malloc(sizeof(wchar_t) + 1);
		ft_bzero(buf, sizeof(wchar_t) + 1);
		ft_wctomb(buf, (wchar_t)wc);
	}
	return (buf);
}

char		*pf_convert_char(va_list ap, t_params *t_arg)
{
	char			*buf;
	unsigned char	c;

	buf = NULL;
	if (t_arg->convert == 'c' && t_arg->lenght == 0)
	{
		c = va_arg(ap, int);
		buf = ft_strnew(1);
		*buf = (char)c;
	}
	else if (t_arg->convert == 'c' && (t_arg->lenght == 4 ||
				t_arg->lenght == 3))
		buf = convert_wchar(ap);
	return (buf);
}
