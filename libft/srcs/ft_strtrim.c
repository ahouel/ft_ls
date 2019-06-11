/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:55:31 by ahouel            #+#    #+#             */
/*   Updated: 2018/01/29 20:35:55 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = (int)ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		++start;
	if (!s[0] || !s[start])
		return (ft_strdup(""));
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end != 0)
		--end;
	if (!(str = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (start + i < end + 1)
	{
		str[i] = s[start + i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
