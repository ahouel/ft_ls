/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:13:39 by ahouel            #+#    #+#             */
/*   Updated: 2016/12/08 13:54:06 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_return(int n, int count, int neg)
{
	char	*ret;

	ret = (char*)malloc(sizeof(char) * (count + 1));
	if (ret == NULL)
		return (NULL);
	ret[count--] = '\0';
	while (count >= 0)
	{
		ret[count--] = n % 10 + 48;
		n = n / 10;
	}
	if (neg == 0)
		ret[0] = '-';
	return (ret);
}

char		*ft_itoa(int n)
{
	int		tmp;
	int		count;
	int		neg;

	neg = -1;
	count = 0;
	if (n == 0)
		++count;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		neg = 0;
		++count;
	}
	tmp = n;
	while (tmp >= 1)
	{
		tmp = tmp / 10;
		++count;
	}
	return (ft_itoa_return(n, count, neg));
}
