/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:23:06 by ahouel            #+#    #+#             */
/*   Updated: 2019/06/11 12:05:28 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Ajoute + ou @ a la fin des permission selon les attributs
*/

static char		get_xattr(char *path)
{
	acl_t	tmp;
	char	buf[124];

	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}

/*
**	Set Chmod (permissions)
*/

static void		set_chmod(t_file *file, char *out)
{
	unsigned short	mode;
	int				i;

	mode = file->st_mode;
	i = 3;
	while (--i > -1)
	{
		if (mode & EXE)
			out[i * 3 + 3] = 'x';
		if (mode & WRITE)
			out[i * 3 + 2] = 'w';
		if (mode & READ)
			out[i * 3 + 1] = 'r';
		mode = mode >> 3;
	}
	if (S_ISUID & file->st_mode)
		out[3] = out[3] == '-' ? 'S' : 's';
	if (S_ISGID & file->st_mode)
		out[6] = out[6] == '-' ? 'S' : 's';
	if (S_ISVTX & file->st_mode)
		out[9] = out[9] == '-' ? 'T' : 't';
}

/*
**	Ecrit le type et les permissions du fichier
*/

static void		print_chmod(t_file *file)
{
	char	out[12];

	ft_memset(out, '-', 10);
	out[11] = 0;
	S_ISDIR(file->st_mode) ? out[0] = 'd' : 0;
	S_ISCHR(file->st_mode) ? out[0] = 'c' : 0;
	S_ISBLK(file->st_mode) ? out[0] = 'b' : 0;
	S_ISFIFO(file->st_mode) ? out[0] = 'p' : 0;
	S_ISLNK(file->st_mode) ? out[0] = 'l' : 0;
	S_ISSOCK(file->st_mode) ? out[0] = 's' : 0;
	set_chmod(file, out);
	out[10] = get_xattr(file->path);
	ft_printf("%s ", out);
}

/*
**	Print time, last argument is year if last modification's date is older
**	than 6 month.
*/

static void		print_time(t_env *e, t_file *file)
{
	time_t	today;
	char	*out;

	out = NULL;
	time(&today);
	if (!(out = ctime(&file->st_time)))
		exit_error(0, e);
	if (today - file->st_time < SIX_MONTH)
		ft_printf("%.12s ", out + 4);
	else
		ft_printf("%.6s%6.4s ", out + 4, out + 20);
}

/*
**	Ecrit chaque infos avec la commande -l
*/

void			print_infos(t_env *e, t_file *file, size_t lens[4])
{
	print_chmod(file);
	ft_printf("%*s ", lens[0], file->nlink);
	ft_printf("%-*s ", lens[1], file->u_name);
	ft_printf(" %-*s ", lens[2], file->g_name);
	ft_printf(" %*s ", lens[3], file->size);
	print_time(e, file);
}
