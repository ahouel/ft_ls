/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_memjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:05:16 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/22 19:25:44 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	*malloc_cpy(unsigned char *ret, void *p, size_t len)
{
	if (!(ret = ft_memalloc(len)))
		return (NULL);
	ret = ft_memcpy(ret, p, len);
	free(p);
	return (ret);
}

void					*pf_memjoin2(void *p1, size_t len1, void *p2,
		size_t len2)
{
	unsigned char	*ret;

	ret = NULL;
	if (p1 && p2)
	{
		ret = ft_memjoin(p1, len1, p2, len2);
		free(p1);
		free(p2);
	}
	else if (!p1 && !p2)
		return (NULL);
	else if (!p1)
		ret = malloc_cpy(ret, p2, len2);
	else if (!p2)
		ret = malloc_cpy(ret, p1, len1);
	return ((void*)ret);
}
