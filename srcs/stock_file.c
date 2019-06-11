/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:55:43 by ahouel            #+#    #+#             */
/*   Updated: 2019/06/11 13:18:03 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Fix le path (ajoute un / au dir si besoin, join avec le name)
*/

static char		*fix_path(t_env *e, char *name, char *dir)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	while (dir[++i])
		;
	if (dir[i] != '/')
	{
		if (!(dir = ft_strjoin(dir, "/")))
			exit_error(0, e);
		tmp = dir;
	}
	if (!(dir = ft_strjoin(dir, name)))
		exit_error(0, e);
	tmp ? free(tmp) : 0;
	return (dir);
}

/*
**	Enregistre les stats de chaque file pour le -l
*/

static t_file	*store_stats(t_env *e, t_file *file, struct stat *stats)
{
	if (!(file->nlink = ft_itoa(stats->st_nlink)))
		exit_error(0, e);
	file->u_name = getpwuid(stats->st_uid)->pw_name;
	file->g_name = getgrgid(stats->st_gid)->gr_name;
	if (!(file->size = ft_itoa(stats->st_size)))
		exit_error(0, e);
	return (file);
}

/*
**	Creation d'un nouveau maillon de la liste chainee
**	pour un dossier donne en parametre
*/

static t_file	*new_file(t_env *e, char *name, char *dir)
{
	t_file		*new;
	char		*path;
	struct stat	stats;

	new = NULL;
	path = fix_path(e, name, dir);
	if (!(new = ft_memalloc(sizeof(t_file))))
		exit_error(0, e);
	if (!(new->path = ft_strdup(path)))
		exit_error(0, e);
	if (!(new->name = ft_strdup(name)))
		exit_error(0, e);
	if (lstat(path, &stats))
		p_error(new->name);
	path ? free(path) : 0;
	new->st_mode = stats.st_mode;
	new->st_time = stats.st_mtime;
	e->total_blocks += stats.st_blocks;
	if (e->arg & ARG_1L)
		return (store_stats(e, new, &stats));
	return (new);
}

/*
**	Stock le nouvel element par defaut (ordre ascii)
*/

void			stock_file(t_env *e, t_dirent *ent, t_file **alst, char *dir)
{
	t_file	*new;
	t_file	*tmp;
	t_file	*prev;

	if (e->arg & ARG_1A || *ent->d_name != H_FILE)
		new = new_file(e, ent->d_name, dir);
	else
		return ;
	tmp = *alst;
	prev = NULL;
	while (tmp)
	{
		if (ft_strcmp(new->name, tmp->name) < 0)
			break ;
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		prev->next = new;
	else
		*alst = new;
	new->next = tmp;
}
