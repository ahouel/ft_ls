/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:36:22 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/23 15:49:43 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_params	*get_color2(t_params *t_arg, const char *format, int *i,
		int *j)
{
	if (ft_strncmp(format + (*i), "red", (size_t)(*j)) == 0 ||
			ft_strncmp(format + (*i), "RED", (size_t)(*j)) == 0)
		t_arg->flags[6] = 1;
	if (ft_strncmp(format + (*i), "green", (size_t)(*j)) == 0 ||
			ft_strncmp(format + (*i), "GREEN", (size_t)(*j)) == 0)
		t_arg->flags[6] = 2;
	if (ft_strncmp(format + (*i), "yellow", (size_t)(*j)) == 0 ||
			ft_strncmp(format + (*i), "YELLOW", (size_t)(*j)) == 0)
		t_arg->flags[6] = 3;
	if (ft_strncmp(format + (*i), "blue", (size_t)(*j)) == 0 ||
			ft_strncmp(format + (*i), "BLUE", (size_t)(*j)) == 0)
		t_arg->flags[6] = 4;
	if (ft_strncmp(format + (*i), "magenta", (size_t)(*j)) == 0 ||
			ft_strncmp(format + (*i), "MAGENTA", (size_t)(*j)) == 0)
		t_arg->flags[6] = 5;
	if (ft_strncmp(format + (*i), "cyan", (size_t)(*j)) == 0 ||
			ft_strncmp(format + (*i), "CYAN", (size_t)(*j)) == 0)
		t_arg->flags[6] = 6;
	if (ft_strncmp(format + (*i), "white", (size_t)(*j)) == 0 ||
			ft_strncmp(format + (*i), "WHITE", (size_t)(*j)) == 0)
		t_arg->flags[6] = 7;
	return (t_arg);
}

static t_params	*get_color(t_params *t_arg, const char *format, int *i)
{
	int	j;

	j = 0;
	++(*i);
	while (format[(*i) + j] && format[(*i) + j] != '}')
		++j;
	t_arg = get_color2(t_arg, format, i, &j);
	(*i) += j;
	return (t_arg);
}

t_params		*pf_get_flags(t_params *t_arg, const char *format, int *i)
{
	while (format[*i] == '#' || format[*i] == '0' || format[*i] == ' ' ||
			format[*i] == '+' || format[*i] == '-' || format[*i] == 'I' ||
			format[*i] == '{')
	{
		if (format[*i] == '#')
			t_arg->flags[0] = 1;
		if (format[*i] == '0')
			t_arg->flags[1] = 1;
		if (format[*i] == ' ')
			t_arg->flags[2] = 1;
		if (format[*i] == '+')
			t_arg->flags[3] = 1;
		if (format[*i] == '-')
			t_arg->flags[4] = 1;
		if (format[*i] == 'I')
			t_arg->flags[5] = 1;
		if (format[*i] == '{')
			t_arg = get_color(t_arg, format, i);
		++(*i);
	}
	return (t_arg);
}
