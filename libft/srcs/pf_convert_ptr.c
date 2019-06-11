/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:45:40 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/22 17:55:06 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_str(va_list ap)
{
	char	*str;

	str = NULL;
	str = va_arg(ap, char*);
	if (str)
		str = ft_strdup(str);
	return (str);
}

static char	*convert_wstr(va_list ap)
{
	char	*str;
	wchar_t	*wstr;
	size_t	wlen;

	str = NULL;
	wstr = NULL;
	wlen = 0;
	wstr = va_arg(ap, wchar_t*);
	if (wstr == NULL)
		return (ft_strdup("(null)"));
	wlen = ft_wstrlen(wstr);
	if (!(str = (char*)malloc(sizeof(wchar_t) * wlen + 1)))
		return (NULL);
	ft_bzero(str, sizeof(wchar_t) * wlen + 1);
	ft_wstrtostr(str, wstr);
	return (str);
}

static char	*convert_ptr(va_list ap)
{
	void	*ptr;
	char	*str;

	ptr = NULL;
	str = NULL;
	ptr = va_arg(ap, void*);
	str = ft_ulldtoa_base((size_t)ptr, 16);
	ptr = str;
	str = ft_strjoin("0x", str);
	free(ptr);
	return (str);
}

char		*pf_convert_ptr(va_list ap, t_params *t_arg)
{
	char	*str;

	str = NULL;
	if (t_arg->convert == 's' && t_arg->lenght == 0)
		str = convert_str(ap);
	else if (t_arg->convert == 's' && (t_arg->lenght == 3 ||
				t_arg->lenght == 4))
		str = convert_wstr(ap);
	else if (t_arg->convert == 'p')
		str = convert_ptr(ap);
	if (!str)
		str = ft_strdup("(null)");
	return (str);
}
