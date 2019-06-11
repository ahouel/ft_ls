/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:04:58 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/03 10:19:28 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = NULL;
	mem = (void*)malloc(size);
	if (mem != NULL)
		ft_memset(mem, 0, size);
	return (mem);
}
