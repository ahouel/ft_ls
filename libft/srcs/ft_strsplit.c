/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:34:09 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/12 18:02:18 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strsplit_count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (!s[0])
		++count;
	while (s[i])
	{
		if (s[i] != c)
		{
			++count;
			while (s[i] && s[i] != c)
				++i;
		}
		if (s[i])
			++i;
	}
	return (count);
}

static char			**ft_strsplit_fill_tab(char const *s, char c, char **tab)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				++i;
			tab[index] = ft_strsub(s, start, (i - start));
			if (tab[index] == NULL)
				return (NULL);
			++index;
		}
		if (s[i])
			++i;
	}
	tab[index] = NULL;
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	count;
	char			**tab;

	if (!s)
		return (NULL);
	count = ft_strsplit_count_words(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	tab = ft_strsplit_fill_tab(s, c, tab);
	return (tab);
}
