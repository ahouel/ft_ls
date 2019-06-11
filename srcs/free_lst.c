/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:39:41 by ahouel            #+#    #+#             */
/*   Updated: 2019/06/11 12:46:32 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Free la liste utilisee pour les fichiers
*/

void	free_lst(t_file **alst)
{
	t_file	*file;
	t_file	*tmp;

	file = *alst;
	while (file)
	{
		tmp = file;
		file = file->next;
		tmp->name ? free(tmp->name) : 0;
		tmp->path ? free(tmp->path) : 0;
		tmp->nlink ? free(tmp->nlink) : 0;
		tmp->size ? free(tmp->size) : 0;
		free(tmp);
	}
}
