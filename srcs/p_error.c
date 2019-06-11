/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:09:12 by ahouel            #+#    #+#             */
/*   Updated: 2019/06/11 10:46:59 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Affiche perror en annoncant ls et le nom du fichier avant
*/

void	p_error(char *dir)
{
	ft_printf("ls: %s: ", dir);
	perror("");
}
