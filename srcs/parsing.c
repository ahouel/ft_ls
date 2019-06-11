/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:14:40 by ahouel            #+#    #+#             */
/*   Updated: 2019/06/11 12:03:41 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Parcourt le tableau des options voir si celle demandee est valide
*/

static void	valid_arg(char arg, const int args[MAX_ARG][2], t_env *e)
{
	int	i;

	i = -1;
	while (++i < MAX_ARG)
	{
		if (arg == args[i][1])
		{
			e->arg |= args[i][0];
			break ;
		}
	}
	if (i == MAX_ARG)
	{
		e->invalid = arg;
		exit_error(ERR_OPTION, e);
	}
}

/*
**	Ajoute l'argument dans l'env s'il est valide
*/

static int	check_arg(char *arg, t_env *e)
{
	int			i;
	const int	args[MAX_ARG][2] =
	{	{ARG_1L, 'l'},
		{ARG_1R, 'r'},
		{ARG_1A, 'a'},
		{ARG_2R, 'R'},
		{ARG_1T, 't'}
	};

	i = 0;
	while (arg[++i])
		valid_arg(arg[i], args, e);
	return (1);
}

/*
**	Lecture des parametres envoyes au programme
**	Renvois au premier argument qui n'est pas une option
*/

int			parsing(int ac, char **av, t_env *e)
{
	int	i;

	i = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1])
		check_arg(av[i], e);
	return (i);
}
