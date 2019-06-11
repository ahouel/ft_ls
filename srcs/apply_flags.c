/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:19:04 by ahouel            #+#    #+#             */
/*   Updated: 2019/06/11 18:23:46 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
static void test(t_file **alst)
{
	t_file	*file;
	int	i;

	i = 0;
	file = *alst;
	ft_printf("############################################\n");
	while (file && i < 5)
	{
		ft_printf("%s -> %ld\n", file->name, file->st_time);
		file = file->next;
	}
	ft_printf("############################################\n");
}

static void testy(t_file **alst)
{
	t_file	*f1;
	t_file	*f2;
	t_file	*f3;

	f1 = ft_memalloc(sizeof(t_file));
	f2 = ft_memalloc(sizeof(t_file));
	f3 = ft_memalloc(sizeof(t_file));
	f1->name = ft_strdup("F1");
	f2->name = ft_strdup("F2");
	f3->name = ft_strdup("F3");
	f1->next = f2;
	f2->next = f3;
	f1->st_time = 3;
	f2->st_time = 2;
	f3->st_time = 1;
	*alst = f1;
}
*/
/*
**	Applique le -t : tri par date
*/

static void blbl(t_file **alst, t_file *replace)
{
	t_file	*file;
	t_file	*tmp;

	file = *alst;
	tmp = 0;
//	ft_printf("replacing %s\n", replace->name);
	while (file)
	{
		if (file->st_time < replace->st_time)
		{
			tmp ? (tmp->next = replace) : (*alst = replace);
			replace->next = file;
			return ;
		}
		tmp = file;
		file = file->next;
	}
}

static void	apply_1t(t_file **alst)
{
	t_file	*file;
	t_file	*tmp;
	time_t	time;

	file = *alst;
	tmp = 0;
	time = -1L;
	while (file)
	{
//		if (time < -1)
//			ft_printf("bipbip\n");
		if (time != -1 && file->st_time > time)
		{
//			test(alst);
//			ft_printf("%s -> tmp %p -> %p\nfile %p -> %p\n",
//				   	file->name, tmp, tmp->next, file, file->next);
//			test(alst);
			tmp ? (tmp->next = file->next) : 0;
			blbl(alst, file);
		//	ft_printf("%p\n", file->next);
			time = -1;
			tmp = 0;
			file = *alst;
//			test(alst);
		}
		else
		{
			time = file->st_time;
			tmp = file;
			file = file->next;
		}
	}
//	test(alst);
}

/*
**	Applique le -r : reverse list
*/

static void	apply_1r(t_file **alst)
{
	t_file	*cur;
	t_file	*prev;
	t_file	*next;

	cur = *alst;
	prev = NULL;
	next = NULL;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

/*
**	Applique le -r et -t
*/

void		apply_flags(t_env *e, t_file **alst)
{
	if (e->arg & ARG_1T)
		apply_1t(alst);
	if (e->arg & ARG_1R)
		apply_1r(alst);
}
