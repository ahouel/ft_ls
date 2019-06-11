/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:27:23 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/22 18:58:08 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	pf_fbinary_count(size_t len, size_t *a)
{
	size_t	count;
	int		i;

	i = 0;
	count = 1;
	while ((len + (*a)) % 8 != 0)
		++(*a);
	while (len > 0)
	{
		--len;
		++i;
		if (i == 9)
		{
			i = 1;
			count += 2;
		}
	}
	return (count);
}

static char		*pf_fbinary_fill(size_t *i, size_t *len, char *buf, char *tmp)
{
	size_t	a;

	a = 0;
	while ((*i) < (*len))
	{
		if (((*i) + 1) % 10 == 0 && (*i) != 0)
			tmp[(*i)] = ' ';
		else if (((*i) + 1) % 5 == 0 && (*i) != 0)
			tmp[(*i)] = '.';
		else
			tmp[(*i)] = buf[a++];
		++(*i);
	}
	return (tmp);
}

static char		*pf_flag_binary(char *buf)
{
	char	*tmp;
	size_t	i;
	size_t	a;
	size_t	len;
	int		count;

	i = 0;
	a = 0;
	len = ft_strlen(buf);
	count = pf_fbinary_count(len, &a);
	len += count + a;
	if (!(tmp = ft_strnew(len)))
		return (NULL);
	while (a > 0)
	{
		tmp[i] = '0';
		if (i % 4 == 0 && i != 0)
			tmp[i] = '.';
		else
			--a;
		++i;
	}
	tmp = pf_fbinary_fill(&i, &len, buf, tmp);
	free(buf);
	return (tmp);
}

static char		*flag_zero(t_params *t_arg, char *buf)
{
	char	*tmp;

	tmp = NULL;
	if (!(*buf == '0' && buf[1] == '\0'))
	{
		if (t_arg->convert == 'x')
			tmp = ft_strdup("0x");
		else if (t_arg->convert == 'X')
			tmp = ft_strdup("0X");
	}
	if (t_arg->convert == 'o' && *buf != '0')
		tmp = ft_strdup("0");
	return (tmp);
}

char			*pf_apply_flag(t_params *t_arg, char *buf)
{
	char	*tmp;
	char	*ptr;

	tmp = NULL;
	ptr = NULL;
	if (t_arg->flags[0] == 1 && *buf)
	{
		if (t_arg->convert == 'b')
			return (pf_flag_binary(buf));
		tmp = flag_zero(t_arg, buf);
	}
	if (t_arg->flags[2] == 1 && (t_arg->convert == 'd' ||
				t_arg->convert == 'i') && t_arg->neg == 0)
		tmp = ft_strdup(" ");
	if (t_arg->flags[3] == 1 && t_arg->neg == 0)
		tmp = ft_strdup("+");
	if (tmp)
	{
		ptr = buf;
		buf = ft_strjoin(tmp, buf);
		free(ptr);
		free(tmp);
	}
	return (buf);
}
