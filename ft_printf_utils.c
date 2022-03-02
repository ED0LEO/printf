/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:17 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/16 21:28:56 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	contains_char(char *s, char c, t_options *ops)
{
	if (*s == '\0')
		return (0);
	if (*s == c)
		return (1);
	consider_extra_option(s, ops);
	while (*s && (ft_isdigit(*s) || *s == '-' || *s == '.'
			|| *s == '#' || *s == ' ' || *s == '+'))
		s++;
	if (*s == c)
		return (1);
	else
		return (0);
}

char	*ft_str_tolower(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}

long long	max_width(const char *s)
{
	long long	n;

	s++;
	n = ft_atoi(s);
	return (n);
}

void	consider_extra_option(const char *s, t_options *ops)
{
	while (*s && (ft_isdigit(*s) || *s == '-' || *s == '.'
			|| *s == '#' || *s == ' ' || *s == '+'))
	{
		if (!ops->width && *s == '0')
			ops->zero = 1;
		if (ft_isdigit(*s) & !ops->width && *(s - 1) != '.')
			ops->width = ft_atoi_ex(s);
		if (*s == '#')
			ops->hash = 1;
		if (*s == '.')
		{
			ops->dot = 1;
			ops->mw = max_width(s);
		}
		if (*s == '-')
			ops->minus = 1;
		if (*s == ' ' && !ops->plus)
			ops->space = 1;
		if (*s == '+' && !ops->space)
			ops->plus = 1;
		s++;
	}
	if (ops->minus)
		ops->zero = 0;
}

int	find_type(char *s, t_options *ops)
{
	nully(ops);
	if (contains_char(s, 'c', ops))
		ops->type = 'c';
	else if (contains_char(s, 's', ops))
		ops->type = 's';
	else if (contains_char(s, 'p', ops))
		ops->type = 'p';
	else if (contains_char(s, 'd', ops))
		ops->type = 'd';
	else if (contains_char(s, 'i', ops))
		ops->type = 'i';
	else if (contains_char(s, 'u', ops))
		ops->type = 'u';
	else if (contains_char(s, 'x', ops))
		ops->type = 'x';
	else if (contains_char(s, 'X', ops))
		ops->type = 'X';
	else if (contains_char(s, '%', ops))
		ops->type = '%';
	else
		return (0);
	return (1);
}
