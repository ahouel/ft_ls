/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:29:50 by ahouel            #+#    #+#             */
/*   Updated: 2019/06/11 12:37:54 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Affiche le lien symbolique et ce qu'il pointe si -l
*/

static void		print_fifo(t_env *e, t_file *file, size_t len)
{
	char	link[NAME_MAX + 1];

	if (e->arg & ARG_1L)
	{
		ft_bzero(link, NAME_MAX + 1);
		readlink(file->path, link, NAME_MAX);
		ft_printf("%s%s%s -> %s", COLOR_LINK, file->name, COLOR_NORM, link);
	}
	else
		ft_printf("%s%s%-*s", COLOR_LINK, file->name, len, COLOR_NORM);
}

/*
**	Affiche un objet, puis le nombre d'espaces ou le '\n' avec -l
**	grace au printf. Ajoute egalement la couleur
*/

static void		print_file(t_env *e, t_file *file, size_t len_max)
{
	size_t	len;

	len = len_max - ft_strlen(file->name) + LEN_C_NORM;
	if (S_ISDIR(file->st_mode))
	{
		if (file->st_mode & S_IWOTH)
			ft_printf("%s%s%-*s", file->st_mode & S_ISVTX ?
					COLOR_DIR_T : COLOR_DIR_W, file->name, len, COLOR_NORM);
		else
			ft_printf("%s%s%-*s", COLOR_DIR, file->name, len, COLOR_NORM);
	}
	else if (S_ISFIFO(file->st_mode))
		ft_printf("%s%s%-*s", COLOR_FIFO, file->name, len, COLOR_NORM);
	else if (S_ISLNK(file->st_mode))
		print_fifo(e, file, len);
	else if (S_ISCHR(file->st_mode))
		ft_printf("%s%s%-*s", COLOR_CHAR_DEV, file->name, len, COLOR_NORM);
	else if (file->st_mode & IS_EXE)
		ft_printf("%s%s%-*s", COLOR_EXE, file->name, len, COLOR_NORM);
	else
		ft_printf("%-*s", len_max, file->name);
	if (file->next && e->arg & ARG_1L)
		ft_putchar(NL);
}

/*
**	Definit la len max des objets a afficher
**	selon le plus grand (+ 1 espace)
**	Uniquement sans l'option -l
*/

static size_t	set_len(t_file **alst)
{
	t_file	*file;
	size_t	max;
	size_t	len;

	max = 0;
	file = *alst;
	while (file)
	{
		len = ft_strlen(file->name);
		if (len > max)
			max = len;
		file = file->next;
	}
	return (max + 1);
}

/*
**	Prend la longueur max de chaque champs pour tous les aligner
*/

static void		set_max_lens(size_t lens[4], t_file **alst)
{
	t_file	*file;
	int		i;

	i = -1;
	while (++i < 4)
	{
		lens[i] = 0;
	}
	file = *alst;
	while (file)
	{
		if (ft_strlen(file->nlink) > lens[0])
			lens[0] = ft_strlen(file->nlink);
		if (ft_strlen(file->u_name) > lens[1])
			lens[1] = ft_strlen(file->u_name);
		if (ft_strlen(file->g_name) > lens[2])
			lens[2] = ft_strlen(file->g_name);
		if (ft_strlen(file->size) > lens[3])
			lens[3] = ft_strlen(file->size);
		file = file->next;
	}
}

/*
**	Affichage du ls
*/

void			output(t_env *e, t_file **alst)
{
	t_file	*file;
	size_t	len_max;
	size_t	lens[4];

	if (e->arg & ARG_1L)
	{
		set_max_lens(lens, alst);
		len_max = 0;
		e->total_blocks > 0 ? ft_printf("total %lld\n", e->total_blocks) : 0;
		e->total_blocks = 0;
	}
	else
		len_max = set_len(alst);
	file = *alst;
	while (file)
	{
		if (e->arg & ARG_1L)
			print_infos(e, file, lens);
		print_file(e, file, file->next ? len_max : 0);
		file = file->next;
	}
	*alst ? ft_putchar(NL) : 0;
}
