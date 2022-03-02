/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/17 17:23:04 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_options
{
	char			type;
	unsigned char	hash;
	unsigned char	dot;
	unsigned char	zero;
	unsigned char	minus;
	unsigned char	space;
	unsigned char	plus;
	long long int	width;
	long long int	mw;
}				t_options;

void		print_fills(t_options *ops, int *super_count, int *i);
void		ft_dot_cx(t_options *ops, void *t, int *super_count);
void		ft_dot_s(t_options *ops, void *t, int *super_count);
void		ft_print_dot(t_options *ops, void *t, int *super_count);
int			count_hexes_dot(t_options *ops, void *t);
int			ft_count_dot(t_options *ops, void *t);
void		ft_dot_p(t_options *ops, void *t, int *super_count);
int			ft_dot_bf(t_options *ops, void *t);
int			ft_dot_af(t_options *ops, void *t);
void		ft_dot_nums(t_options *ops, void *t, int *super_count);
void		ft_dot_x(t_options *ops, void *t, int *super_count);
void		ft_putnbr_dot(int n, int fd, int *super_count, t_options *ops);
void		ft_dot(t_options *ops, void *t, int *super_count);
int			ft_count_len(t_options *ops, void *t);
void		ft_pr(t_options *ops, void *t, int *super_count);
void		nully(t_options *ops);
void		ft_count_num(int n, int *super_count, t_options *ops);
int			ft_atoi(const char *str);
int			ft_atoi_ex(const char *str);
void		cons_flags(int *super_count, t_options *ops, void *t);
int			count_flags(char *s);
void		ft_print_type(t_options *ops, void *t, int *super_count);
void		converter_big(void *t, int base, unsigned char **str);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *s1);
void		ft_shift_left(char **str, int size, char c);
void		ft_shift_bytes(char **str, int size, int bytes);
int			ft_tolower(int c);
int			ft_isdigit(int c);
void		ft_putnbr_fd(int n, int fd, int *super_count, t_options *ops);
void		ft_putstr_fd(char *s, int fd);
char		*ft_str_tolower(char *s);
t_options	*create_ops(char c);
void		consider_extra_option(const char *s, t_options *ops);
int			find_type(char *s, t_options *ops);
int			ft_printf(const char *s, ...);
size_t		ft_strlen(const char *s);
int			contains_char(char *s, char c, t_options *ops);
char		*converter(void *t, int base, int big);
void		ft_print_string(t_options *ops, void *t, int *super_count);
void		ft_print_pointer(t_options *ops, void *t, int *super_count);
void		ft_print_nums(t_options *ops, void *t, int *super_count);
void		ft_print_lowhex(t_options *ops, void *t, int *super_count);
void		ft_print_caphex(t_options *ops, void *t, int *super_count);

#endif
