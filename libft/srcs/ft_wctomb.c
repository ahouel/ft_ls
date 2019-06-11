/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:15:28 by ahouel            #+#    #+#             */
/*   Updated: 2017/06/05 17:47:34 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inner_wctomb(char **s, wchar_t wc, int octets)
{
	if (octets == 1)
		(*s)[0] = (char)wc;
	else if (octets == 2)
	{
		(*s)[0] = 0xc0 + (wc >> 6);
		(*s)[1] = 0x80 + (wc & 0x3f);
	}
	else if (octets == 3)
	{
		(*s)[0] = 0xe0 + (wc >> 12);
		(*s)[1] = 0x80 + ((wc >> 6) & 0x3f);
		(*s)[2] = 0x80 + (wc & 0x3f);
	}
	else if (octets == 4)
	{
		(*s)[0] = 0xf0 + (wc >> 18);
		(*s)[1] = 0x80 + ((wc >> 12) & 0x3f);
		(*s)[2] = 0x80 + ((wc >> 6) & 0x3f);
		(*s)[3] = 0x80 + (wc & 0x3f);
	}
	return (octets);
}

int			ft_wctomb(char *s, wchar_t wc)
{
	if (s == NULL)
		return (0);
	if (wc < 0x80)
		return (inner_wctomb(&s, wc, 1));
	else if (wc < 0x800)
		return (inner_wctomb(&s, wc, 2));
	else if (wc < 0x10000)
		return (inner_wctomb(&s, wc, 3));
	else if (wc < 0x200000)
		return (inner_wctomb(&s, wc, 4));
	return (-1);
}
