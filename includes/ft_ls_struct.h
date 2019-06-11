/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:40:39 by ahouel            #+#    #+#             */
/*   Updated: 2019/06/11 12:17:58 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_STRUCT_H
# define FT_LS_STRUCT_H

# define COLOR_DIR		"\033[1;36m"
# define COLOR_LINK		"\033[5;35m"
# define COLOR_FIFO		"\033[33m"
# define COLOR_EXE		"\033[31m"
# define COLOR_DIR_T	"\033[30;42m"
# define COLOR_DIR_W	"\033[30;43m"
# define COLOR_CHAR_DEV	"\033[34;43m"
# define COLOR_NORM		"\033[0m"

# define LEN_C_NORM		4

# define ARG_1L			1
# define ARG_1R			2
# define ARG_1A			4
# define ARG_2R			8
# define ARG_1T			16

# define SIX_MONTH		15552000L

# define EXE			1
# define WRITE			2
# define READ			4

# define IS_EXE			73

# define MAX_ARG		5

# define ERR_OPTION		1

# define H_FILE			'.'
# define SPACE			' '
# define NL				'\n'

typedef struct dirent	t_dirent;

typedef struct	s_file
{
	char			*name;
	char			*path;
	mode_t			st_mode;
	char			*nlink;
	char			*u_name;
	char			*g_name;
	char			*size;
	time_t			st_time;
	struct s_file	*next;
}				t_file;

typedef struct	s_env
{
	char			invalid;
	int				arg;
	long long int	total_blocks;
}				t_env;
#endif
