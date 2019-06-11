/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:55:45 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/28 15:29:58 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_buffer(va_list ap, const char *restrict format, int *ret)
{
	int		i;
	char	*buf;
	int		len;

	i = 0;
	buf = NULL;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			++i;
		(*ret) += i;
		i > 0 ? buf = pf_memjoin2(buf, (size_t)(*ret - i),
				ft_strndup(format, i), (size_t)i) : 0;
		len = 0;
		if (format[i] == '%' && format[i + 1])
			buf = pf_memjoin2(buf, (size_t)(*ret),
					pf_args(ap, format, &i, &len), (size_t)len);
		len < 0 ? write(1, buf, (*ret - i)) : 0;
		len < 0 ? ((*ret) = -1) : ((*ret) += len);
		format += i;
		i = 0;
		if ((format[0] == '%' && !(format[1])) || (*ret) == -1)
			break ;
	}
	return (buf);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		ret;
	char	*buf;

	buf = NULL;
	ret = 0;
	va_start(ap, format);
	if (format)
		buf = pf_buffer(ap, format, &ret);
	va_end(ap);
	if (ret > 0)
		write(1, buf, (size_t)ret);
	buf ? free(buf) : 0;
	return (ret);
}
