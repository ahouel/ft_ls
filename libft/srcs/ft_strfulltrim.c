/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfulltrim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:49:37 by lgaveria          #+#    #+#             */
/*   Updated: 2018/01/31 14:14:43 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_str(char const *s, int len)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	if (!(new = malloc(sizeof(char) * len)))
		return (NULL);
	len = 0;
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[i])
	{
		while (s[i] && !(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			new[len++] = s[i++];
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		if (s[i])
			new[len++] = ' ';
	}
	new[len] = '\0';
	return (new);
}

char		*ft_strfulltrim(char const *s)
{
	int		i;
	int		count;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[i])
	{
		while (s[i] && !(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		{
			i++;
			count++;
		}
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		count++;
	}
	return (fill_str(s, count));
}
