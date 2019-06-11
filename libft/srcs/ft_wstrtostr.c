/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:26:51 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/10 17:07:05 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wstrtostr(char *s, wchar_t *ws)
{
	int	ret;
	int	i;

	ret = 0;
	i = 1;
	if (!s)
		return (-1);
	while (*ws && i > 0)
	{
		i = ft_wctomb(s, *ws);
		s += i;
		ret += i;
		ws++;
	}
	return (ret);
}
