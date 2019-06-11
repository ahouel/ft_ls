/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:30:22 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/23 15:19:41 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*pre_ptr(t_params *t_arg, char *buf)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	j = 0;
	i = (int)ft_strlen(buf);
	if (i == 3 && buf[2])
	{
		buf = ft_strdup("0x");
		--i;
	}
	if (i - 2 < t_arg->precision)
	{
		tmp = ft_strnew(2 + t_arg->precision);
		tmp = ft_strncat(tmp, buf, 2);
		j = 1;
		while (++j < t_arg->precision - i + 4)
			tmp[j] = '0';
		tmp = ft_strncat(tmp, buf + 2, i - 2);
		buf ? free(buf) : 0;
		return (tmp);
	}
	return (buf);
}

static char	*pre_nbr(t_params *t_arg, char *buf)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	i = 0;
	j = 0;
	if (*buf == '0' && (t_arg->convert == 'x' || t_arg->convert == 'X' ||
				(t_arg->convert == 'o' && t_arg->flags[0] == 0) ||
				t_arg->convert == 'd' || t_arg->convert == 'i' ||
				t_arg->convert == 'u'))
		*buf = '\0';
	if ((size_t)t_arg->precision > ft_strlen(buf) - t_arg->neg)
	{
		tmp = ft_strnew(t_arg->precision + t_arg->neg);
		i = t_arg->precision - ft_strlen(buf) + (2 * t_arg->neg);
		if (t_arg->neg == 1)
			tmp[j++] = '-';
		while (j < i)
			tmp[j++] = '0';
		tmp = ft_strcat(tmp, buf + t_arg->neg);
		free(buf);
		return (tmp);
	}
	return (buf);
}

static char	*pre_wstr(t_params *t_arg, char *buf)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = buf;
	j = 0;
	i = t_arg->precision - 1;
	if (i > -1 && buf[i] < -64 && buf[i] > -128)
	{
		++i;
		while (i > -1 && buf[i] < -64 && buf[i] > -128)
			--i;
		if (i > 0)
			--i;
	}
	else if (i > -1 && buf[i] < 0 && buf[i] > -65)
		--i;
	buf = ft_strndup(buf, i + 1);
	free(ptr);
	return (buf);
}

char		*pf_apply_precision(t_params *t_arg, char *buf)
{
	char	*ptr;

	ptr = buf;
	if (t_arg->convert == 's' && t_arg->precision < (int)ft_strlen(buf))
	{
		if (t_arg->lenght == 4)
			return (pre_wstr(t_arg, buf));
		buf = ft_strndup(buf, t_arg->precision);
		ptr ? free(ptr) : 0;
		return (buf);
	}
	else if (t_arg->convert == 'd' || t_arg->convert == 'i' ||
			t_arg->convert == 'o' || t_arg->convert == 'u' ||
			t_arg->convert == 'x' || t_arg->convert == 'X' ||
			t_arg->convert == 'D')
		return (pre_nbr(t_arg, buf));
	else if (t_arg->convert == 'p')
		return (pre_ptr(t_arg, buf));
	return (buf);
}
