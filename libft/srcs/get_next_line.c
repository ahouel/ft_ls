/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 08:53:14 by ahouel            #+#    #+#             */
/*   Updated: 2017/12/12 14:41:53 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_checker(t_gnl *t_fd, char **line)
{
	char	*tmp1;
	char	*tmp2;

	if ((tmp1 = ft_strchr(t_fd->save, '\n')) != NULL)
	{
		*tmp1 = '\0';
		*line = ft_strdup(t_fd->save);
		tmp2 = t_fd->save;
		t_fd->save = ft_strdup(tmp1 + 1);
		free(tmp2);
		return (1);
	}
	return (0);
}

static int	gnl_reader(t_gnl *t_fd, char **line)
{
	char	tmp[BUFF_SIZE + 1];
	char	*ptr;
	int		ret;

	while ((ret = read(t_fd->fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		ptr = t_fd->save;
		t_fd->save = ft_strjoin(t_fd->save, tmp);
		free(ptr);
		if (gnl_checker(t_fd, line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (t_fd->save[0] == '\0' && ret == 0)
		return (0);
	return (2);
}

int			gnl_from_fd(t_gnl *t_fd, char **line)
{
	int			ret;

	if (gnl_checker(t_fd, line) == 1)
		return (1);
	if ((ret = gnl_reader(t_fd, line)) != 2)
		return (ret);
	*line = ft_strdup(t_fd->save);
	t_fd->save[0] = '\0';
	return (1);
}

t_gnl		*gnl_new_elem(const int fd, t_gnl **alst)
{
	t_gnl	*new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->save = ft_strdup("");
	new->next = *alst;
	*alst = new;
	return (new);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*alst = NULL;
	t_gnl			*tmp;

	tmp = alst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (gnl_from_fd(tmp, line));
		tmp = tmp->next;
	}
	if (!(tmp = gnl_new_elem(fd, &alst)))
		return (-1);
	return (gnl_from_fd(tmp, line));
}
