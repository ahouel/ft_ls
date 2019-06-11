/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:33:07 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/31 16:43:16 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_apply_color(t_params *t_arg, char *buf, int *len)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (!(tmp = ft_strnew(*len + 9)))
		return (NULL);
	tmp2 = tmp + 5;
	tmp = ft_strcat(tmp, "\x1b[3");
	tmp[3] = t_arg->flags[6] + 48;
	tmp[4] = 'm';
	tmp2 = ft_memmove(tmp2, buf, (size_t)(*len));
	tmp2 = tmp + (*len) + 5;
	tmp2 = ft_strcat(tmp2, "\x1b[0m");
	free(buf);
	(*len) += 9;
	return (tmp);
}
