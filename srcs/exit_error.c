/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:40:53 by ahouel            #+#    #+#             */
/*   Updated: 2019/06/06 11:08:54 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Une erreur, on quitte le programme en liberant au prealable
**	la memoire allouee, puis on envoit un message correspondant
*/

void	exit_error(int error, t_env *e)
{
	ft_printf("%{RED}s\t", "ls:");
	if (error == ERR_OPTION)
		ft_printf("%{RED}s -- %{MAGENTA}c\n", "illegal option", e->invalid);
	else
		perror("Error ");
	exit(EXIT_FAILURE);
}
