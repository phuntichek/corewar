/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:28:54 by fmelda            #+#    #+#             */
/*   Updated: 2019/04/24 19:17:13 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <math.h>
# include "../libft/get_next_line.h"
# define RED(string)     "\e[0;31m" string "\x1b[0m"
# define GREEN(string)   "\e[0;32m" string "\x1b[0m"
# define YELLOW(string)  "\e[0;33m" string "\x1b[0m"
# define BLUE(string)    "\e[0;34m" string "\x1b[0m"
# define PURPLE(string)  "\e[0;35m" string "\x1b[0m"
# define CYAN(string)    "\e[0;36m" string "\x1b[0m"
# define WHITE(string)   "\e[0;37m" string "\x1b[0m"
# define SIZE 100000

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_all
{
	char			flag[3];
	char			*fmt;
	char			*fmt_cp;
	int				i;
	va_list			args;
	int				len;
	int				acc;
	char			size;
	char			type;
	int				count;
	int				sign;
}					t_all;

/*
** MEM
*/

void				*ft_memset(void *d, int c, size_t n);
void				*ft_memccpy(void *destination,
	const void *source, int c, size_t n);
void				*ft_memcpy(void *out, const void *in, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_memalloc(size_t size);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				ft_bzero(void *d, size_t n);
void				ft_memdel(void **ap);
void				ft_free_arr(char **arr);
int					ft_len_arr(char **arr);

/*
**STR || PUT || IS || TO
*/

char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
char				*ft_strncpy(char *dest, const char *src, unsigned int n);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *string, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_itoa(int n);
char				*ft_strnew(size_t size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
int					ft_isspace(char c);
void				ft_swap(int *a, int *b);
void				ft_putrstr(char *str);
int					ft_sqrt(int nb);
void				ft_foreach(int *tab, int lenght, void (*f) (int));
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int ch);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
void				ft_striter(char *s, void (*f)(char *));
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);

/*
**BONUS PART
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					get_next_line(const int fd, char **line);
int					ft_is_number(char *str);
void				*ft_realloc(void *ptr, size_t size);
void				ft_lstpushback(t_list **start, t_list *new);
char				*ft_l_itoa(long n);
long				ft_round(double n, int precision);
long				ft_abs(int x);
long long int		ft_llabs(long long x);
long int			ft_labs(long int x);
long double			ft_fabsl(long double x);
double				ft_fabs(double x);
char				*ft_l_itoa_base(long value, int base);
int					ft_strnchr(const char *s, int c);
int					ft_pow(int x, unsigned int y);

t_all				*init_st(t_all *st);
int					ft_printf(const char *fmt, ...);
void				reinit_st(t_all *st);
int					parse(t_all *st);
int					pre_format(t_all *st);
void				fill_flags(t_all *st);
void				fill_len_acc(t_all *st);
void				fill_size(t_all *st);
void				do_for_string(t_all *st);
void				string_with_flags(t_all *st, char *s, int len);
void				do_for_char(t_all *st);
void				do_for_percent(t_all *st);
void				do_for_int(t_all *st);
void				do_for_u_int(t_all *st);
void				u_int_with_flags(t_all *st, char *s, int len);
void				do_for_oct(t_all *st);
void				do_for_hex(t_all *st);
void				do_for_pointer(t_all *st);
void				null_p_with_acc(t_all *st);
void				do_for_null(t_all *st);
void				null_with_acc(t_all *st);
void				crossroad_for_int(t_all *st);
void				crossroad_for_u(t_all *st);
void				crossroad_for_oct(t_all *st);
void				crossroad_for_hex(t_all *st);
void				crossroad_for_floats(t_all *st);
void				do_for_hh_int(t_all *st);
void				do_for_h_int(t_all *st);
void				do_for_l_int(t_all *st);
void				do_for_ll_int(t_all *st);
void				oct_with_flags(t_all *st, char *s, int len);
void				poiner_with_flags(t_all *st, char *s, int len);
char				*fill_with_hex(t_all *st, char *s, int len);
void				fill_with_oct(t_all *st, char **s, int len);
void				hex_with_flags(t_all *st, char *s, int len);
void				do_for_positive(t_all *st, char *s, int len);
void				do_for_negative(t_all *st, char *s, int len);
void				int_with_flags(t_all *st, char *s, int len);
char				*check_letter(char *s, t_all *st);
void				do_for_hh_uns(t_all *st);
void				do_for_h_uns(t_all *st);
void				do_for_l_uns(t_all *st);
void				do_for_ll_uns(t_all *st);
void				do_for_hh_oct(t_all *st);
void				do_for_h_oct(t_all *st);
void				do_for_l_oct(t_all *st);
void				do_for_ll_oct(t_all *st);
void				do_for_hh_hex(t_all *st);
void				do_for_h_hex(t_all *st);
void				do_for_l_hex(t_all *st);
void				do_for_ll_hex(t_all *st);
void				do_for_floats(t_all *st);
void				do_for_l_floats(t_all *st);
int					ft_fwrite(const char flag, const char *input, size_t len);
int					ft_fwrite_c(const char flag, const char *input, size_t len);
char				*ft_convert_float(t_all *st, long double num);
void				do_for_positive_hex(t_all *st, char *s, int len);
void				insert_flag_2(t_all *st);
void				null_with_hex(t_all *st);
void				null_with_no_acc_hex(t_all *st);
void				foo(char **s, t_all *st, int *len);
void				do_for_u_no_flags(t_all *st, char *s, int len);
void				put_number_with_minus(t_all *st, int len, char *s);
void				put_number_with_flag(t_all *st, int len, char *s);
void				put_null(t_all *st);
char				*ft_ll_itoa_base(long long value, int base);
char				*ft_ll_itoa(long long n);

#endif
