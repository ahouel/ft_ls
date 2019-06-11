/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:14:21 by ahouel            #+#    #+#             */
/*   Updated: 2017/03/29 16:05:59 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# define PF_NB_FLAGS 7

typedef struct	s_params
{
	int				*flags;
	unsigned int	width;
	int				precision;
	int				lenght;
	char			convert;
	int				neg;
}				t_params;
void			*pf_memjoin2(void *p1, size_t len1, void *p2, size_t len2);
char			*pf_apply_width(t_params *t_arg, char *buf);
char			*pf_apply_flag(t_params *t_arg, char *buf);
char			*pf_apply_precision(t_params *t_arg, char *buf);
char			*pf_apply_color(t_params *t_arg, char *buf, int *len);
char			*pf_convert_nbr(va_list ap, t_params *t_arg);
char			*pf_convert_char(va_list ap, t_params *t_arg);
char			*pf_convert_ptr(va_list ap, t_params *t_arg);
char			*pf_dispatch_convert(va_list ap, t_params *t_arg);
char			*pf_args(va_list ap, const char *format, int *i, int *len);
t_params		*pf_get_flags(t_params *t_arg, const char *format, int *i);
t_params		*pf_get_width(t_params *t_arg, const char *fornat, int *i,
		va_list ap);
t_params		*pf_get_precision(t_params *t_arg, const char *format, int *i,
		va_list ap);
t_params		*pf_get_lenght(t_params *t_arg, const char *format, int *i);
t_params		*pf_get_convert(t_params *t_arg, const char *format, int *i);
int				ft_printf(const char *restrict format, ...);

#endif
