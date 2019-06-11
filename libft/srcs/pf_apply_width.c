/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:28:29 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/22 17:17:24 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*pf_apply_width2(t_params *t_arg, char *buf, int *i, char *tmp)
{
	char	c;
	int		j;

	c = ' ' + (t_arg->flags[1]) * 16;
	j = ft_strlen(buf);
	while (++(*i) < (int)t_arg->width - j)
		tmp[(*i)] = c;
	j = -1;
	while (buf[++j])
	{
		if (t_arg->flags[1] == 1 && (buf[j] == 'x' || buf[j] == 'X'))
		{
			tmp[1] = buf[j];
			buf[j] = c;
		}
		if ((t_arg->flags[1] == 1 || t_arg->flags[2]) &&
				(t_arg->convert == 'd' || t_arg->convert == 'i') &&
				(buf[j] == '+' || buf[j] == '-' || buf[j] == ' '))
		{
			tmp[0] = buf[j];
			buf[j] = c;
		}
		tmp[(*i)++] = buf[j];
	}
	return (tmp);
}

char		*pf_apply_width(t_params *t_arg, char *buf)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = -1;
	if (t_arg->convert == 'c' && !(*buf) && t_arg->flags[4] == 1)
	{
		++i;
		++(t_arg->width);
	}
	if (t_arg->width <= ft_strlen(buf))
		return (buf);
	tmp = ft_strnew(t_arg->width);
	if (t_arg->flags[4] == 1)
	{
		while (buf[++i])
			tmp[i] = buf[i];
		--i;
		while (++i < (int)t_arg->width)
			tmp[i] = ' ';
	}
	else
		tmp = pf_apply_width2(t_arg, buf, &i, tmp);
	buf ? free(buf) : 0;
	return (tmp);
}
