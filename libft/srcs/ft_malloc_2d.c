/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 13:42:06 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/27 19:45:24 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc_2d(int x, int y)
{
	char	**map;
	int		i;

	i = -1;
	map = NULL;
	if (!(map = (char**)malloc(sizeof(char*) * (y + 1))))
		return (NULL);
	while (++i < y)
		if (!(map[i] = (char*)malloc(sizeof(char) * (x + 1))))
		{
			while (--i)
				free(map[i]);
			free(map);
			return (NULL);
		}
	map[y] = NULL;
	return (map);
}
