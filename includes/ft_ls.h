/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:10:34 by ahouel            #+#    #+#             */
/*   Updated: 2019/06/11 12:04:24 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>

# include <limits.h>

# include "libft.h"
# include "ft_ls_struct.h"

void	p_error(char *dir);
void	exit_error(int error, t_env *e);
int		parsing(int ac, char **av, t_env *e);
void	stock_file(t_env *e, t_dirent *ent, t_file **alst, char *dir);
void	ft_ls(t_env *e, char *name);
void	apply_flags(t_env *e, t_file **alst);
void	free_lst(t_file **alst);
void	output(t_env *e, t_file **alst);
void	print_infos(t_env *e, t_file *file, size_t lens[9]);

#endif
