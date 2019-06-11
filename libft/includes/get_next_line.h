/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 08:53:11 by ahouel            #+#    #+#             */
/*   Updated: 2017/01/12 15:55:09 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 1000

typedef struct		s_gnl
{
	char			*save;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
