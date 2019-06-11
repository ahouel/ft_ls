/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:56:21 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/28 15:05:54 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_params	*pf_reset_struct(t_params *t_arg)
{
	int	i;

	i = 0;
	while (i < PF_NB_FLAGS)
		t_arg->flags[i++] = 0;
	t_arg->width = 0;
	t_arg->precision = -1;
	t_arg->lenght = 0;
	t_arg->convert = '\0';
	t_arg->neg = 0;
	return (t_arg);
}

static t_params	*pf_set_struct(void)
{
	t_params	*t_arg;

	if (!(t_arg = (t_params*)malloc(sizeof(t_params))))
		return (NULL);
	if (!(t_arg->flags = (int*)malloc(sizeof(int) * PF_NB_FLAGS)))
	{
		free(t_arg);
		return (NULL);
	}
	t_arg = pf_reset_struct(t_arg);
	return (t_arg);
}

static t_params	*pf_struct(t_params *t_arg, const char *format, int *i,
		va_list ap)
{
	t_arg = pf_reset_struct(t_arg);
	t_arg = pf_get_flags(t_arg, format, i);
	t_arg = pf_get_width(t_arg, format, i, ap);
	t_arg = pf_get_precision(t_arg, format, i, ap);
	t_arg = pf_get_lenght(t_arg, format, i);
	t_arg = pf_get_convert(t_arg, format, i);
	if (((t_arg->convert == 'd' || t_arg->convert == 'i' ||
			t_arg->convert == 'o' || t_arg->convert == 'x' ||
			t_arg->convert == 'X' || t_arg->convert == 'u')
			&& t_arg->precision > -1) || t_arg->flags[4] == 1)
		t_arg->flags[1] = 0;
	if (t_arg->flags[3] == 1)
		t_arg->flags[2] = 0;
	if (t_arg->flags[3] && t_arg->convert != 'd' && t_arg->convert != 'i'
			&& t_arg->convert != 'D')
		t_arg->flags[3] = 0;
	return (t_arg);
}

static char		*apply_flags(t_params *t_arg, char *buf, int *len)
{
	int	null;

	null = 0;
	if (t_arg->convert == 'c' && *buf == 0)
	{
		if (t_arg->flags[4] == 1 && t_arg->width > 1)
			null = 1;
		(*len)++;
		if (t_arg->width != 0)
			(t_arg->width)--;
	}
	if (t_arg->precision > -1)
		buf = pf_apply_precision(t_arg, buf);
	buf = pf_apply_flag(t_arg, buf);
	if (t_arg->width != 0)
		buf = pf_apply_width(t_arg, buf);
	(*len) += ft_strlen(buf + null);
	if (t_arg->flags[6] != 0)
		buf = pf_apply_color(t_arg, buf, len);
	return (buf);
}

char			*pf_args(va_list ap, const char *format, int *i, int *len)
{
	t_params	*t_arg;
	char		*buf;

	t_arg = NULL;
	++(*i);
	if (!(t_arg = pf_set_struct()))
		return (NULL);
	t_arg = pf_struct(t_arg, format, i, ap);
	if (t_arg->convert != '\0')
		buf = pf_dispatch_convert(ap, t_arg);
	else
		buf = ft_strnew(0);
	if (t_arg->convert == 'c' && ft_strcmp(buf, "no") == 0)
	{
		(*i) -= 2;
		free(buf);
		free(t_arg->flags);
		free(t_arg);
		(*len) = -1;
		return (NULL);
	}
	buf = apply_flags(t_arg, buf, len);
	free(t_arg->flags);
	free(t_arg);
	return (buf);
}
