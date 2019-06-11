/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:14:41 by ahouel            #+#    #+#             */
/*   Updated: 2018/02/01 14:14:49 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include "get_next_line.h"
# include "ft_printf.h"

void			*ft_memset(void	*b, int c, size_t len);
void			ft_bzero(void *b, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memrchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char	*dest, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
};
typedef struct s_list	t_list;
t_list			*ft_lstnew(void	const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_swap(int *a, int *b);
int				ft_sqrt(int nb);
void			ft_cswap(char *a, char *b);
char			*ft_strrev(char *str);
void			ft_div_mod(int a, int b, int *div, int *mod);
int				ft_factorial(int nb);
void			ft_putlst(t_list *lst);
char			*ft_lldtoa_base(long long int nb, int base);
char			*ft_ulldtoa_base(unsigned long long int nb, int base);
int				ft_wctomb(char *s, wchar_t wc);
int				ft_wstrtostr(char *s, wchar_t *ws);
size_t			ft_wstrlen(const wchar_t *ws);
size_t			ft_strnlen(const char *str, char c);
size_t			ft_abs(int i);
char			*ft_stradd(const char *str, size_t len);
void			*ft_memjoin(const void *s1, size_t len1, const void *s2,
		size_t len2);
int				ft_reader(const int fd, char **line);
char			**ft_malloc_2d(int x, int y);
void			ft_free_2d(char **str);
int				ft_str_isdigit(const char *str);
void			ft_bswap(void *bytes, size_t len);
int				ft_iswhitespace(char c);
size_t			ft_tablen(char **tab);
char			*ft_strfulltrim(char const *s);
#endif
