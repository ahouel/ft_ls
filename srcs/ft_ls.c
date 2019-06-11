/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:40:23 by ahouel            #+#    #+#             */
/*   Updated: 2019/06/11 17:59:22 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	is_valid_dir(char *name)
{
	if (!ft_strcmp(name, ".") || !ft_strcmp(name, ".."))
		return (0);
	return (1);
}

/*
**	Appel recursif de ls sur les dossier avec -R
*/

static void	ls_recursive(t_env *e, t_file **alst)
{
	t_file	*file;

	file = *alst;
	while (file)
	{
		if (S_ISDIR(file->st_mode) && is_valid_dir(file->name))
		{
			ft_printf("\n%s:\n", file->path);
			ft_ls(e, file->path);
		}
		file = file->next;
	}
}

/*
**	Fonction principale appelee avec le nom du dossier a traiter
**	On l'ouvre, on le parcourt puis on applique les flags
**	On la rappel pour chaque dossier si -R
*/

void		ft_ls(t_env *e, char *name)
{
	DIR			*dir;
	t_dirent	*ent;
	t_file		*file_lst;

	file_lst = NULL;
	if (!(dir = opendir(name)))
	{
		p_error(name);
		return ;
	}
//	ft_putendl("1");
	e->total_blocks = 0;
	while ((ent = readdir(dir)))
		stock_file(e, ent, &file_lst, name);
//	ft_putendl("2");
	if (closedir(dir))
		p_error(name);
	if (file_lst)
		apply_flags(e, &file_lst);
//	ft_putendl("3");
	output(e, &file_lst);
//	ft_putendl("4");
	if (e->arg & ARG_2R)
		ls_recursive(e, &file_lst);
	free_lst(&file_lst);
//	ft_putendl("5");
}
