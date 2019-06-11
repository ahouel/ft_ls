/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:09:50 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/23 16:30:48 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_n_join(char *s1, char *s2)
{
	char	*buf;

	buf = NULL;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
	{
		buf = ft_strdup(s2);
		free(s2);
	}
	else if (!s2)
	{
		buf = ft_strdup(s1);
		free(s1);
	}
	else
	{
		buf = ft_strjoin(s1, s2);
		free(s1);
		free(s2);
	}
	return (buf);
}

int			ft_reader(const int fd, char **line)
{
	char	*tmp;

	tmp = NULL;
	while (get_next_line(fd, &tmp))
		*line = free_n_join(*line, tmp);
	if (!(*line))
		return (-1);
	return (1);
}
